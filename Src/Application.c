/*
 * Application.c
 *
 *  Created on: Feb 24, 2019
 *      Author: mlebek
 */
#include "Application.h"

Application gApp;

void initApplication(Application* application)
{
	initMultiplexer(application->mplex);
	initChessboard(application->chessboard);
}

void updateChessboard(Chessboard* brd, uint8_t changeIndex)
{
	if(brd->board_[changeIndex].val != 0)
	{
		brd->tmp_fig = brd->board_[changeIndex];
		brd->board_[changeIndex].val = 0;
	}
	else
	{
		brd->board_[changeIndex] = brd->tmp_fig;
		brd->tmp_fig.val  0;
	}
}

