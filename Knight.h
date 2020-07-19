#include "ChessBoard.h"
#ifndef KNIGHT_H
#define KNIGHT_H

class Knight {
	public:
		int currentPosX;
		int currentPosY;
		int movementXY[4]; //Number of knight movements
		ChessBoard board;
		
		Knight(int, int);
		int countMoves(int, int);

	private:
		bool isConvenient(int, int);	
};

#endif
