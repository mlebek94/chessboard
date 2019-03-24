/*
 * Application.h
 *
 *  Created on: Feb 24, 2019
 *      Author: mlebek
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "chessboard.h"
#include "multiplexer.h"

typedef struct Application
{
	Multiplexer mplex;
	Chessboard chessboard;
}Application;

extern Application gApp;

void initApplication(Application* application);
void updateChessboard(Chessboard* brd, uint8_t changeIndex);
Cell* pollMultiplexer(Multiplexer* m);

#endif /* APPLICATION_H_ */
