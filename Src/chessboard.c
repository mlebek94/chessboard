/*
 * chessboard.c
 *
 *  Created on: Feb 24, 2019
 *      Author: mlebek
 */
#include "chessboard.h"
#include "multiplexer.h"

Figure backLine[8] =
{
		{.type = rook, .color = 0},
		{.type = knight, .color = 0},
		{.type = bishop, .color = 0},
		{.type = queen, .color = 0},
		{.type = king, .color = 0},
		{.type = bishop, .color = 0},
		{.type = knight, .color = 0},
		{.type = rook, .color = 0}
};

Chessboard gChessboard = {0};

void initChessboard(Chessboard* board)
{
	uint8_t i = 0, j = 0;
	Cell tmp_cell = (Cell){.isOccupied = false};

	board->currentChangeIndex = 0;

//	board->board_[0].fig.val = (uint8_t)6;
//	board->board_[0].pos = (Cell){.row_ = ROW_1, .col_ = COL_A, .isOccupied = false} ;

	//columns
	for(i = 0; i < 8 ; i++)
	{
		//rows
		for(j = 0; j < 8 ; j++)
		{
			uint8_t index = j+(8*i);
			//minor & major
			if( (i == 0) || (i == 7))
			{
				board->board_[index] = backLine[j];
				if(i == 0)
				{
					board->board_[index].color = 1;
				}
			}
			//pawns
			else if((i == 1) || (i == 6))
			{
				board->board_[index] = (Figure){.type = pawn, .color = 0};
				if(i == 1)
				{
					board->board_[index].color = 1;
				}
			}
			//empty
			else
			{
				board->board_[index] = (Figure){.type = 0, .color = 0};
			}
//			board->board_[index].pos = tmp_cell;
			tmp_cell.col_ <<= 1;
		}
		tmp_cell.col_ = COL_A;
		tmp_cell.row_ <<= 1;
	}
}
