
#include "stm32f4xx.h"
#include "system_timetick.h"
#include "UART.h"
#include "FSMC.h"
#include "eeprom.h"
#include "utils.h"
#include "Servo.h"
#include "Calculator.h"
#include "OperationMode.h"
#include "HomeSwitch.h"
#include "Kinematic.h"
#include "Encoder.h"
#include <string.h>
bool rx_flag = 0;
uint16_t save_pos_count = 0;

bool vSGUI_ready_flag = 0;
uint8_t Mode=IDLE;

float HOME_OFFSET[6];
float MAX_OF_TRIP[6];
char str_tx_uart[500];

void Uart_Program(void);
char p;

HEXAPOD_DATA_STRUCT st_hexapod_data;

int main()
{		
	uint32_t ui_delay;
	UART_DMA_Init();

	//Home Off set for Servo
	HOME_OFFSET[0] = 33.65f;
	HOME_OFFSET[1] = 34.29f;
	HOME_OFFSET[2] = 30.39f;
	HOME_OFFSET[3] = 28.73f;
	HOME_OFFSET[4] = 31.57f;
	HOME_OFFSET[5] = 31.77f;
	
	MAX_OF_TRIP[0] = 144.977f;
	MAX_OF_TRIP[1] = 150.024f;
	MAX_OF_TRIP[2] = 146.865f;
	MAX_OF_TRIP[3] = 140.612f;
	MAX_OF_TRIP[4] = 147.100f;
	MAX_OF_TRIP[5] = 147.818f;
	
	uint8_t Pos_save_in_byte[4];
	
	//Init..................................................................................
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	FSMC_Init();
	EEP_Init();
	Servo_Home_Switch_Init();


	for(int i=0;i<MAX_SERVO_NUM;i++)
	{		
		EEP_ReadBytes(Pos_save_in_byte,i*4,4);
		Servo_pos_pre[i]=Bytes2float(Pos_save_in_byte);
		st_servo_data[i].enc_cur_pos = Servo_pos_pre[i];
	}
	
	for(int i=0;i<6;i++)
	{
		Servo_pos_distance[i]=0;
		Servo_dir[i]=0;

	}
	
 

	// Timer Initial must be placed here
	Servo_Control_Timer_Init();
	
	ENC_Timer_Init();
	ENC_Reset();
	
	Uart_Cmd_Update("\n");
	Ex_Usart_SendData(str_tx_uart);
	//........................................finish Init and enable timer2 for encoder cheking
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_Cmd(TIM2, ENABLE);
	

	//Start hand-shaking GUI.........................................................
	vSGUI_ready_flag = 0;	
	while(!vSGUI_ready_flag)
	{
		Uart_Cmd_Update("lSTM Ready-");
		ui_delay = 168000000/2;
		while(ui_delay--);
	}	
	Uart_Cmd_Update("lSTM and VSGUI connected-");
	
	
	//State machine loop.....................................................
	rx_flag = 0;
	while(1)
	{
		if (rx_flag)
			{
				switch(Mode)
				{
					case IDLE:
						//Meanwhile, Timer2 keeps counting and update to GUI
						IdleMode();
						break;
					case TESTING:
						TestingMode();
						break;
					case HOMESCAN:
						HomeScanMode();
						break;
					case INVERSEKINEMATIC:
						InverseKinematicMode();
						break;
					default:
						break;
				}
				rx_flag=0;
			}		
	}
}


//Receiving interrupt by DMA.......................................................
void DMA1_Stream1_IRQHandler(void)
{	
	DMA_Cmd(DMA1_Stream1, DISABLE);
	/* Clear the DMA1_Stream1 TCIF1 pending bit */
  DMA_ClearITPendingBit(DMA1_Stream1, DMA_IT_TCIF1);
		
	Uart_Program();
	rx_flag = 1;
	DMA_Cmd(DMA1_Stream1, ENABLE);	
	
}
//.........................................................................

//Handling Uart data from GUI
void Uart_Program(void)
{
	uint8_t Pos_save_in_byte[4];
	switch(rxbuff[0])
	{
		
		case 'c': // Hand shake
		{
			if(rxbuff[1] == 'r')
				vSGUI_ready_flag = 1;
			break;
		}
		case 't': // Testing Mode
		{
			Servo_pos_cur[0]=asc2dou(rxbuff[2])*100+asc2dou(rxbuff[3])*10+asc2dou(rxbuff[4])+asc2dou(rxbuff[6])/10+asc2dou(rxbuff[7])/100+asc2dou(rxbuff[8])/1000;
			Servo_pos_cur[1]=asc2dou(rxbuff[10])*100+asc2dou(rxbuff[11])*10+asc2dou(rxbuff[12])+asc2dou(rxbuff[14])/10+asc2dou(rxbuff[15])/100+asc2dou(rxbuff[16])/1000;
			Servo_pos_cur[2]=asc2dou(rxbuff[18])*100+asc2dou(rxbuff[19])*10+asc2dou(rxbuff[20])+asc2dou(rxbuff[22])/10+asc2dou(rxbuff[23])/100+asc2dou(rxbuff[24])/1000;
			Servo_pos_cur[3]=asc2dou(rxbuff[26])*100+asc2dou(rxbuff[27])*10+asc2dou(rxbuff[28])+asc2dou(rxbuff[30])/10+asc2dou(rxbuff[31])/100+asc2dou(rxbuff[32])/1000;
			Servo_pos_cur[4]=asc2dou(rxbuff[34])*100+asc2dou(rxbuff[35])*10+asc2dou(rxbuff[36])+asc2dou(rxbuff[38])/10+asc2dou(rxbuff[39])/100+asc2dou(rxbuff[40])/1000;
			Servo_pos_cur[5]=asc2dou(rxbuff[42])*100+asc2dou(rxbuff[43])*10+asc2dou(rxbuff[44])+asc2dou(rxbuff[46])/10+asc2dou(rxbuff[47])/100+asc2dou(rxbuff[48])/1000;

			Mode=TESTING;
			break;
		}
		
		case 'h': // Home scan Mode
		{
			if(rxbuff[1]=='s') //set direction to home switch
			{
				// Reset Home Status
				Home_Scan_Begin();
				//Set HOMESCAN next state after setting direction
				Mode=HOMESCAN;
				
				for(int i=0;i<6;i++)
				{
					
					if(rxbuff[i+3]=='l') //To the left
					{
						if((i==0)||(i==2)||(i==4))
						{
							Servo_pos_cur[i]=150;
							Servo_pos_pre[i]=0;
						}
						else
						{
							Servo_pos_cur[i] = 0;
							Servo_pos_pre[i] = 150;
						}
					}
					else if(rxbuff[i+3]=='r') // To the right
					{
						if((i==0)||(i==2)||(i==4))
						{
							Servo_pos_cur[i] = 0;
							Servo_pos_pre[i] = 150;		
						}			
						else
						{
							Servo_pos_cur[i] = 150;
							Servo_pos_pre[i] = 0;							
						}							
					}
				}
				
			}
			else if(rxbuff[1] == 'e') //Set home offset for each nuts		
			{

					for(int i=0;i<MAX_SERVO_NUM;i++)
					{		
						
						Servo_pos_cur[i] = HOME_OFFSET[i] ;
						Servo_pos_pre[i] = HOME_OFFSET[i] ;
						
						
						//save current position to EEPROM
						float2Bytes(Pos_save_in_byte , 	HOME_OFFSET[i]);
						EEP_WriteBytes(Pos_save_in_byte , i*4, 4);

					}
					
				//Reset encoder
				ENC_Reset();
				FSMC_ENC_Reset();

					
				//Set IDLE next state	
				Mode=IDLE;
			}
			break;
		}
		
		case 'k': // Test Kinematic Mode
		{
			if(rxbuff[1]=='i')
			{
				st_hexapod_data.x 		= is_minus(rxbuff[2])*(asc2dou(rxbuff[3])*10+asc2dou(rxbuff[4]) + asc2dou(rxbuff[6])/10+asc2dou(rxbuff[7])/100+asc2dou(rxbuff[8])/1000);
				st_hexapod_data.y 		= is_minus(rxbuff[10])*(asc2dou(rxbuff[11])*10+asc2dou(rxbuff[12]) + asc2dou(rxbuff[14])/10+asc2dou(rxbuff[15])/100+asc2dou(rxbuff[16])/1000);
				st_hexapod_data.z 		= is_minus(rxbuff[18])*(asc2dou(rxbuff[19])*10+asc2dou(rxbuff[20]) + asc2dou(rxbuff[22])/10+asc2dou(rxbuff[23])/100+asc2dou(rxbuff[24])/1000);
				st_hexapod_data.roll  = is_minus(rxbuff[26])*(asc2dou(rxbuff[27])*10+asc2dou(rxbuff[28]) + asc2dou(rxbuff[30])/10+asc2dou(rxbuff[31])/100+asc2dou(rxbuff[32])/1000);
				st_hexapod_data.pitch = is_minus(rxbuff[34])*(asc2dou(rxbuff[35])*10+asc2dou(rxbuff[36]) + asc2dou(rxbuff[38])/10+asc2dou(rxbuff[39])/100+asc2dou(rxbuff[40])/1000);
				st_hexapod_data.yaw 	= is_minus(rxbuff[42])*(asc2dou(rxbuff[43])*10+asc2dou(rxbuff[44]) + asc2dou(rxbuff[46])/10+asc2dou(rxbuff[47])/100+asc2dou(rxbuff[48])/1000);
				
				Mode = INVERSEKINEMATIC;
				break;
			}			
		}
		
		case 's': // Save position Mode
		{
			for(int i = 0; i < MAX_SERVO_NUM ; i++)
			{
				float2Bytes(Pos_save_in_byte , 	st_servo_data[i].enc_cur_pos);
				EEP_WriteBytes(Pos_save_in_byte , i*4, 4);
			}
			
			Uart_Cmd_Update("lI saved the position successfully-");
			Mode = IDLE;
			break;
		}
		
	}
}
