#ifndef KNIGHT
#define KNIGHT
#include "Knight.h"
#include <iostream>

using namespace std;

Knight::Knight(int _x, int _y) : board() {
	//Entered parameters checked for validity
	if(0 <= _x && _x < BOARD_ROW_LEN)
		currentPosX = _x;
	else {
		currentPosX = 0;
		cout << "The X coordinate of the starting point is assigned to 0 because of entered invalid value." << endl;
	}		
	if(0 <= _y && _y < BOARD_COLUMN_LEN)
		currentPosY = _y;
	else {
		currentPosY = 0;
		cout << "The Y coordinate of the starting point is assigned to 0 because of entered invalid value." << endl;
	}	
	movementXY[0] = -2;
	movementXY[1] = -1;
	movementXY[2] = 1;
	movementXY[3] = 2;
}

bool Knight::isConvenient(int currentPosX, int currentPosY) {
	//Check next move validty
	if(0 <= currentPosX && currentPosX < BOARD_ROW_LEN && 0 <= currentPosY && currentPosY < BOARD_COLUMN_LEN && this->board.matrix[currentPosX][currentPosY] == -1)
		return true;
	else 
		return false;
}

int Knight::countMoves(int currentPosX, int currentPosY) {
	//Count moves 	
	int movesNum = 0;
			
	if(isConvenient(currentPosX, currentPosY)) {
		int moveX;
		int moveY;
					
		for(int index1 = 0; index1 < 4; index1++) {
			moveX = movementXY[index1];
			for(int index2 = 0; index2 < 4; index2++) {
				if(movementXY[index2] * movementXY[index2] != moveX * moveX) {
					moveY = movementXY[index2];
					if(isConvenient(currentPosX + moveX, currentPosY + moveY))
						movesNum++;
				}
			}
		}
	}else
		movesNum = 100;
				
	return movesNum;		
}

#endif
