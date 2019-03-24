/*
 * myTasks.c
 *
 *  Created on: Feb 24, 2019
 *      Author: mlebek
 */
//#include "multiplexer.h"
//#include "chessboard.h"
#include "usart.h"
#include "Application.h"

//extern Application gApp;
//extern Multiplexer gMplex;
//extern Chessboard gChessboard;

void StartChessboardTask(void const * argument)
{
	/* USER CODE BEGIN StartUsbTask */
//	initChessboard(&gChessboard);
	initApplication(&gApp);
	/* Infinite loop */
	for(;;)
	{
		if(xQueueReceive(mplexQueueHandle, (void*)&gChessboard.currentChangeIndex, 10) == pdTRUE)
		{
			updateChessboard(&gApp.chessboard);
		}
		osDelay(10);
	}
	/* USER CODE END StartUsbTask */
}

void StartMultiplexerTask(void const * argument)
{
	/* USER CODE BEGIN Start_multiplexerTask */
	initMultiplexer(&gMplex);
	/* Infinite loop */
	for(;;)
	{
		scanMatrix(&gMplex);
		if(gMplex.matrixChanged)
		{
			//do sth
			gMplex.matrixChanged = false;
		}
		osDelay(250);
	}
	/* USER CODE END Start_multiplexerTask */
}

void StartLedTask(void const * argument)
{
	/* USER CODE BEGIN StartLedTask */
	/* Infinite loop */
	for(;;)
	{
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		osDelay(250);
	}
	/* USER CODE END StartLedTask */
}

void StartComTask(void const * argument)
{
	/* USER CODE BEGIN StartUsbTask */
	uint8_t txBuff[30] = {"Hello World!"};
	uint16_t len = 0;

	//	 ++MessageCounter;
	len = sprintf(txBuff, "Hello World! \n\r");
	/* Infinite loop */
	for(;;)
	{
		HAL_UART_Transmit(&huart2, txBuff, len, 1000);
		osDelay(1000);
	}
	/* USER CODE END StartUsbTask */
}
