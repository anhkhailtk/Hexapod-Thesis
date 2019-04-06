#include <stdbool.h>
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "UART.h"
#include "HomeSwitch.h"
#include <string.h>

uint8_t 	txbuff[BUFF_TX];
uint8_t 	rxbuff[BUFF_RX];
char frame[100] = {0};

static char str_uart_update[100];
	
uint8_t len = 0;

void UART_DMA_Init(void)
{
	GPIO_InitTypeDef 	GPIO_InitStructure; 
	USART_InitTypeDef USART_InitStructure;   
	DMA_InitTypeDef  	DMA_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;	
   
  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  /* Enable UART clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	/* Enable DMA1 clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

  /* Connect USART3 pins to AF7 */  
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3); 

  /* GPIO Configuration for USART3 Tx */
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* GPIO Configuration for USART Rx */
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
       
  /* USARTx configured as follow:
		- BaudRate = 115200 baud  
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART3, &USART_InitStructure);
	
	/* Enable USART */
  USART_Cmd(USART3, ENABLE);
	
	/* Enable USART3 DMA */
  USART_DMACmd(USART3, USART_DMAReq_Tx, ENABLE); 
	
	/* Enable USART3 DMA */
  USART_DMACmd(USART3, USART_DMAReq_Rx, ENABLE);
	
	/* DMA1 Stream1 Channel4 for USART3 Rx configuration */			
  DMA_InitStructure.DMA_Channel = DMA_Channel_4;  
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART3->DR;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)rxbuff;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = BUFF_RX;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;//DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_Init(DMA1_Stream1, &DMA_InitStructure);
  DMA_Cmd(DMA1_Stream1, ENABLE);
		
	/* Enable DMA Interrupt to the highest priority */
  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

//  /* Transfer complete interrupt mask */
  DMA_ITConfig(DMA1_Stream1, DMA_IT_TC, ENABLE);
	
	
	
	/* DMA1 Stream3 Channel4 for UART4 Tx configuration */			
  DMA_InitStructure.DMA_Channel = DMA_Channel_4;  
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART3->DR;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)txbuff;
  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  DMA_InitStructure.DMA_BufferSize = BUFF_TX;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_Init(DMA1_Stream3, &DMA_InitStructure);
  DMA_Cmd(DMA1_Stream3, ENABLE);
}
//----------------------------------------------------------------------------------------------
// Send Uart Data from token trimmed from tx buffer
void Ex_Usart_SendData(char* UsartData)
{
		//char token[100] = {0x00};		
		//UART_trimline_tx_data(token, str_tx_uart);
		strcat(str_tx_uart, "\n");
		uint16_t string_lenght = strlen(str_tx_uart);
		DMA_Cmd(DMA1_Stream3, DISABLE);	
		memcpy(txbuff, str_tx_uart, string_lenght);
		DMA_ClearFlag(DMA1_Stream3, DMA_FLAG_TCIF3);
		DMA1_Stream3->NDTR = string_lenght;
		DMA_Cmd(DMA1_Stream3, ENABLE);		
		memset(str_tx_uart,0,strlen(str_tx_uart));
}
//----------------------------------------------------------------------------------------------------
//Send encoder position to GUI
void UART_Send_PC_Encoder_Pos(void)
{
	len = 0;
	frame[len++] = 'e';
	for(int index = 0; index < MAX_SERVO_NUM; index++)
	{

		sprintf(frame + len, "%7.3f", st_servo_data[index].enc_cur_pos);
		len += 7;
	
	}
	frame[len] = '-'; // Finish char
	
	Uart_Cmd_Update(frame); 

}
//----------------------------------------------------------------------------------------------
/*
Each information packet is placed between 2 "\n" char, so function below trim the packet befor putting 
it in txbuff
*/
void UART_trimline_tx_data(char* dis, char* src)
{
	int len = strlen(src);
	for(int i = 0; i < strlen(src); i++)
	{
		if(src[i] == 0x0A)
		{
			for(int j = 0; j < i + 1; j++)
			{
				dis[j] = src[j];
			}
			for(int k = 0; k < (strlen(src)); k++)
			{
				src[k] = src[k + strlen(dis)];
			}
			break;
		}
	}
	
}
//----------------------------------------------------------------------------------------------
//Put new packet to string buffer, waiting for sent
void Uart_Cmd_Update(const char* strInput) 
{
	//if 2 strings are similar, skip it
	if(strInput != str_uart_update)
	{
		strcpy(str_uart_update, strInput);
		strcat(str_tx_uart, str_uart_update);
	}
}
