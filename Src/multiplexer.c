/*
 * multiplexer.c
 *
 *  Created on: Feb 23, 2019
 *      Author: mlebek
 */
#include "multiplexer.h"

Multiplexer gMplex = {0};
Cell gBoard[64] = {0};

void initMultiplexer(Multiplexer* mplex)
{
	uint8_t i = 0, j = 0;
	Cell tmp_cell = {0};//{COL_A, ROW_1, 0};
	mplex->matrixChanged = true;		//to send initial matrix state
	tmp_cell.col_ = COL_A;
	tmp_cell.row_ = ROW_1;
	tmp_cell.isOccupied = 0;

	//rows
	for(i = 0; i < 8 ; i++)
	{
		//columns
		for(j = 0; j < 8 ; j++)
		{
			mplex->matrix_[j+(8*i)] = tmp_cell;
			tmp_cell.col_ <<= 1;
		}
		tmp_cell.col_ = COL_A;
		tmp_cell.row_ <<= 1;
	}
}

void scanMatrix(Multiplexer* mplex)
{
	uint8_t i = 0, j = 0;
	Column col_pin = COLUMN_A_OUTPUT_Pin;
	Row row_pin = ROW_1_INPUT_Pin;
//	GPIO_PinState state;

	//columns
	for(i = 0; i < 8 ; i++)
	{
		HAL_GPIO_WritePin(GPIOC, col_pin, GPIO_PIN_SET);
		//rows
		for(j = 0; j < 8 ; j++)
		{
			uint8_t index = j+(8*i);
			//if change
			if((mplex->matrix_[index].isOccupied) != (HAL_GPIO_ReadPin(GPIOB, row_pin)))
			{
				(mplex->matrix_[index].isOccupied) = !(mplex->matrix_[index].isOccupied);
//				mplex->matrixChanged = true;
				xQueueSend(mplexQueueHandle,(void*) &index, 1);
			}
//			if((state = HAL_GPIO_ReadPin(GPIOB, row_pin)) == GPIO_PIN_SET)
//			{
//				mplex->matrix_[j+(8*i)].isOccupied = 1;
//			}
//			else
//			{
//				mplex->matrix_[j+(8*i)].isOccupied = 0;
//			}
			row_pin <<= 1;
		}
		row_pin = ROW_1;
		HAL_GPIO_WritePin(GPIOC, col_pin, GPIO_PIN_RESET);
		col_pin <<= 1;
	}
//	return mplex->matrix_;
}

