/*
 * chessboard.h
 *
 *  Created on: Feb 24, 2019
 *      Author: mlebek
 */

#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include "main.h"
#include "multiplexer.h"

#define WHITE_MASK		0x80
#define BLACK_MASK		0x0

#define WHITE_PAWN		(uint8_t)(WHITE_MASK | 1)
#define WHITE_BISHOP	(uint8_t)(WHITE_MASK | 2)
#define WHITE_KNIGHT	(uint8_t)(WHITE_MASK | 3)
#define WHITE_ROOK		(uint8_t)(WHITE_MASK | 4)
#define WHITE_QUEEN		(uint8_t)(WHITE_MASK | 5)
#define WHITE_KING		(uint8_t)(WHITE_MASK | 6)

#define BLACK_PAWN		(uint8_t)(BLACK_MASK | 1)
#define BLACK_BISHOP	(uint8_t)(BLACK_MASK | 2)
#define BLACK_KNIGHT	(uint8_t)(BLACK_MASK | 3)
#define BLACK_ROOK		(uint8_t)(BLACK_MASK | 4)
#define BLACK_QUEEN		(uint8_t)(BLACK_MASK | 5)
#define BLACK_KING		(uint8_t)(BLACK_MASK | 6)

typedef	union Figure
{
	struct{
		enum{
			none = 0,
			pawn = 1,
			bishop = 2,
			knight = 3,
			rook,
			queen,
			king
		}type:7;
		uint8_t color:1;
	};
	uint8_t val;
}Figure;


typedef struct Square
{
	Cell pos;
	Figure fig;

}Square;

typedef struct Chessboard
{
	//	Multiplexer mplex;
	Figure board_[64];
	Figure tmp_fig;

	uint8_t currentChangeIndex;

}Chessboard;

extern Chessboard gChessboard;

void initChessboard(Chessboard* board);

#endif /* CHESSBOARD_H_ */
