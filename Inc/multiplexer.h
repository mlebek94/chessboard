/*
 * multiplexer.h
 *
 *  Created on: Feb 23, 2019
 *      Author: mlebek
 */

#ifndef MULTIPLEXER_H_
#define MULTIPLEXER_H_

#include "main.h"
#include "cmsis_os.h"

extern osMessageQId mplexQueueHandle;

typedef enum Row
{
	ROW_1 = ROW_1_INPUT_Pin,
	ROW_2 = ROW_2_INPUT_Pin,
	ROW_3 = ROW_3_INPUT_Pin,
	ROW_4 = ROW_4_INPUT_Pin,
	ROW_5 = ROW_5_INPUT_Pin,
	ROW_6 = ROW_6_INPUT_Pin,
	ROW_7 = ROW_7_INPUT_Pin,
	ROW_8 = ROW_8_INPUT_Pin
}Row;


typedef enum Column
{
	COL_A = COLUMN_A_OUTPUT_Pin,
	COL_B = COLUMN_B_OUTPUT_Pin,
	COL_C = COLUMN_C_OUTPUT_Pin,
	COL_D = COLUMN_D_OUTPUT_Pin,
	COL_E = COLUMN_E_OUTPUT_Pin,
	COL_F = COLUMN_F_OUTPUT_Pin,
	COL_G = COLUMN_G_OUTPUT_Pin,
	COL_H = COLUMN_H_OUTPUT_Pin
}Column;

typedef struct Cell
{
	Row row_;// = ROW_1;
	Column col_;//= COL_A;
	uint8_t isOccupied;
}Cell;

typedef struct Multiplexer
{
	Cell matrix_[64] ;//= {0};
	bool matrixChanged;
}Multiplexer;

void initMultiplexer(Multiplexer* mplex);
void scanMatrix(Multiplexer* mplex);

extern Multiplexer gMplex;

#endif /* MULTIPLEXER_H_ */
