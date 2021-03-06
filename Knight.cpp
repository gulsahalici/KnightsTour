#include "Knight.h"
#include <iostream>
#include <cstdlib>

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
		for(int index1 = 0; index1 < 4; index1++) {
			for(int index2 = 0; index2 < 4; index2++) {
				if(abs(movementXY[index2]) != abs(movementXY[index1])) {
					if(isConvenient(currentPosX + movementXY[index1], currentPosY + movementXY[index2]))
						movesNum++;
				}
			}
		}
	}else
		movesNum = 9;
				
	return movesNum;		
}

int Knight::move(int counter) {
	// x-2 y-1, x-1 y-2
	// x+2 y-1, x+1 y-2
	// x+2 y+1, x+1 y+2
	// x-2 y+1, x-1 y+2
	int nextMoveX;
	int nextMoveY;
	int minMoves = 9; // a knight's max movement number(8) + 1
		
	for(int index1 = 0; index1 < 4; index1++) {
		for(int index2 = 0; index2 < 4; index2++) {
			if(abs(movementXY[index2]) != abs(movementXY[index1])) {
				int movesNum = countMoves(currentPosX + movementXY[index1], currentPosY + movementXY[index2]);
				
				if(movesNum < minMoves) {			
					minMoves = movesNum;
					nextMoveX = currentPosX + movementXY[index1];
					nextMoveY = currentPosY + movementXY[index2];
				}
			}
		}
	}
	board.matrix[currentPosX][currentPosY] = counter;
	currentPosX = nextMoveX;
	currentPosY = nextMoveY;
		
	return 0;
}
