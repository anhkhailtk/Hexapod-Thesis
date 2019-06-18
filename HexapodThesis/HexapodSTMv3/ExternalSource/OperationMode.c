#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "OperationMode.h"
#include "Servo.h"
#include "HomeSwitch.h"
#include "Kinematic.h"
#include "UART.h"
#include <math.h>
uint32_t ui_delay;
uint8_t Mode;
bool isDemoMode;
bool isCircleMode;

void CircleMode(void)
{
	Uart_Cmd_Update("lI am in Circle Mode-");
	Uart_Cmd_Update_android("s_lIAICM-"); //I am in Demo Mode
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_Cmd(TIM2, ENABLE);
	const float R = 2.0f;
	float rad = 0.0f;
	while(isCircleMode)
	{
		st_hexapod_data.x = R * cos(rad);
		st_hexapod_data.y = R * sin(rad);
		st_hexapod_data.z = 18.0f;
		st_hexapod_data.roll = 0.0f;
		st_hexapod_data.pitch = 0.0f;
		st_hexapod_data.yaw = 0.0f;
		InverseKinematicMode(false);
		rad += PI / 100000.0f;
		
	}
	Mode = IDLE;
}

void DemoMode(void)
{	
	Uart_Cmd_Update("lI am in Demo Mode-");
	Uart_Cmd_Update_android("s_lIAIDM-"); //I am in Demo Mode
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_Cmd(TIM2, ENABLE);
	while(isDemoMode)
	{
		if(isDemoMode)
		{
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 15.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}
		if(isDemoMode)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 20.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}
		if(isDemoMode)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}
		if(isDemoMode)
		{		
			st_hexapod_data.x = -4.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
		if(isDemoMode)
		{	
		if(Mode == DEMO)
		{		
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = -4.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 4.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
		if(Mode == DEMO)
		{	
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = -6.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}			
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 6.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}			
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = -6.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 6.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = -6.0f;
			InverseKinematicMode(false);
		}	
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 6.0f;
			InverseKinematicMode(false);
		}	
		if(Mode == DEMO)
		{		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
		
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}	
			st_hexapod_data.x = 0.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}				
			st_hexapod_data.x = 4.0f;
			st_hexapod_data.y = 0.0f;
			st_hexapod_data.z = 18.0f;
			st_hexapod_data.roll = 0.0f;
			st_hexapod_data.pitch = 0.0f;
			st_hexapod_data.yaw = 0.0f;
			InverseKinematicMode(false);
		}			
	}
	Mode = IDLE;
}
void TestingMode(void)
{
	Uart_Cmd_Update("lI am in Testing Mode-");
	Uart_Cmd_Update_android("s_lIAITM-"); //I am in Testing Mode
	
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_Cmd(TIM2, ENABLE);
	for(int i=0;i<MAX_SERVO_NUM;i++)
	{
		if(Servo_pos_cur[i] >= MAX_OF_TRIP[i] - 2.0f)
			Servo_pos_cur[i] = MAX_OF_TRIP[i] - 2.0f ;
		else if(Servo_pos_cur[i] <= (HOME_OFFSET[i] + 2.0f))
			Servo_pos_cur[i] = HOME_OFFSET[i] + 2.0f;
	}

	Calcu_Pos(Servo_pos_cur,Servo_pos_pre);
	Pos_servo_all(Servo_pos_distance,Servo_dir, false);
	for(int j=0;j<6;j++)
	{
		Servo_pos_pre[j] = st_servo_data[j].enc_cur_pos;
	}
	IdleMode();
}
void HomeScanMode(void)
{
				//Send status
				Uart_Cmd_Update("lI am in Home Scan Mode-");
				Uart_Cmd_Update_android("s_lIAIHSM-"); //I am in Home Scan Mode
				//Disable timer 2
				TIM_Cmd(TIM2, DISABLE);
//----------------------------------------------------------------------------------------------				
	
				//Release Home switch if it's pressed
				float Servo_pos_init[6]={5,5,5,5,5,5};
				uint8_t Servo_dir_init[6]={0,0,0,0,0,0};
				Pos_servo_all(Servo_pos_init,Servo_dir_init, true);
				
				//pull all nuts to Home switch
				Calcu_Pos(Servo_pos_cur,Servo_pos_pre);
				Pos_servo_all(Servo_pos_distance,Servo_dir, true);	
//----------------------------------------------------------------------------------------------				
				
				/*
				Waiting for all HS pressed, jump into interupt to turn on Home Status flag
				*/
				while((!Home_Status()));
//----------------------------------------------------------------------------------------------								
				//Reset encoder
				for(int i = 0; i < MAX_SERVO_NUM; i++)
				{
					st_servo_data[i].enc_cur_pos = 0;
					st_servo_data[i].set_pos = 0;
				}
				//delay time for stablizing motor
				delay_01ms(50);
//----------------------------------------------------------------------------------------------				
				// Measure the error by calculating the encoder difference
				//Turn on Timer 2 to use encoder 
				TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
				TIM_Cmd(TIM2, ENABLE);
				
				float Servo_pos_offset[6]={10,10,10,10,10,10};
				uint8_t Servo_dir_offset[6]={0,0,0,0,0,0};
				Pos_servo_all(Servo_pos_offset,Servo_dir_offset, true);
				
				delay_01ms(50);
				
				float Servo_pos_offset2[6]={10,10,10,10,10,10};
				uint8_t Servo_dir_offset2[6]={1,1,1,1,1,1};
				Pos_servo_all(Servo_pos_offset2,Servo_dir_offset2, true);
				
				delay_01ms(50);
				
//----------------------------------------------------------------------------------------------				

				
				//Fix Home Switch Error by setting pre-position to encoder difference
				for(int i = 0; i < MAX_SERVO_NUM; i++)
				{
					Servo_pos_cur[i] = 0;
					Servo_pos_pre[i] = st_servo_data[i].enc_cur_pos;
				}
				Calcu_Pos(Servo_pos_cur,Servo_pos_pre);
				Pos_servo_all(Servo_pos_distance,Servo_dir, true);
				
				//Clear string buffer Tx
				memset(str_tx_uart, 0, strlen(str_tx_uart));
				
				//Send Home Finish Flag to GUI
				Uart_Cmd_Update("hfa-");
				Uart_Cmd_Update_android("s_hfa-");				
				Ex_Usart_SendData(str_tx_uart);
				//Turn off Timer 2
				TIM_Cmd(TIM2, DISABLE);
//----------------------------------------------------------------------------------------------								
}
void InverseKinematicMode(bool isInvereKinematicMode)
{
	if(isInvereKinematicMode)
	{
		Uart_Cmd_Update("lI am in Inverse Kinematic Mode-");
		Uart_Cmd_Update_android("s_lIAIIKM-"); // I am in Inverse Kinematic Mode
	}
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_Cmd(TIM2, ENABLE);
	float pos[3];
	float matR[9];
	
	pos_calculate(pos);
	matR_calculate(matR);
	inverse_kinematic(pos,matR,Servo_pos_cur);

	bool kinematic_false_flag = 0;
	for(int i = 0;i < MAX_SERVO_NUM; i++)
	{
		if((Servo_pos_cur[i] > (MAX_OF_TRIP[i] - 2.0f)) || (Servo_pos_cur[i] < (HOME_OFFSET[i] + 2.0f)) || (isnan(Servo_pos_cur[i])))
			kinematic_false_flag = 1;
	}
	
	if(!kinematic_false_flag)
	{
		for(int i=0;i<MAX_SERVO_NUM;i++)
		{
			if(Servo_pos_cur[i] >= MAX_OF_TRIP[i] - 2.0f)
				Servo_pos_cur[i] = MAX_OF_TRIP[i] - 2.0f ;
			else if(Servo_pos_cur[i] <= (HOME_OFFSET[i] + 2.0f))
				Servo_pos_cur[i] = HOME_OFFSET[i] + 2.0f;
		}

		Calcu_Pos(Servo_pos_cur,Servo_pos_pre);
		Pos_servo_all(Servo_pos_distance,Servo_dir, false);
		for(int j=0;j<6;j++)
		{
			Servo_pos_pre[j] = st_servo_data[j].enc_cur_pos;
		}
	}
	else
	{
		if(isInvereKinematicMode)
		{
			Uart_Cmd_Update("lI can not calculate inverse kinematic-");
			Uart_Cmd_Update_android("s_lICNCIK-"); //I can not calculate inverse kinematic
		}
	}
	if(isInvereKinematicMode)
	{	
		Uart_Cmd_Update("lI am in Idle Mode-");
		Uart_Cmd_Update_android("s_lIAIIM-"); //I am in Idle Mode
	}
	if(isInvereKinematicMode)
	{	
		Mode = IDLE;
	}
}
void IdleMode(void)
{
	//Turn on Timer 2
		
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_Cmd(TIM2, ENABLE);	
	
	Uart_Cmd_Update("lI am in Idle Mode-");
	Uart_Cmd_Update_android("s_lIAIIM-"); //I am in Idle Mode
}
