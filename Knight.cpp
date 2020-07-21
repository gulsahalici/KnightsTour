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

int Knight::countOrMove(int _currentPosX, int _currentPosY, int counter) {
	//count's variable
	int movesNum = 0;
	//move's variables
	int nextMoveX;
	int nextMoveY;
	int minMoves = 9; // a knight's max movement number(8) + 1
	
	for(int index1 = 0; index1 < 4; index1++) {
		for(int index2 = 0; index2 < 4; index2++) {
			if(abs(movementXY[index2]) != abs(movementXY[index1])) {
				if(counter == -1) { //when counter=-1, the number of knight's moves is counted
					if(isConvenient(_currentPosX, _currentPosY)) {
						if(isConvenient(_currentPosX + movementXY[index1], _currentPosY + movementXY[index2]))
							movesNum++;
					}else
						return minMoves;
				}else { //when counter!=-1 ,knight is moved
					int movesNum = countOrMove(currentPosX + movementXY[index1], currentPosY + movementXY[index2], -1);
				
					if(movesNum < minMoves) {			
						minMoves = movesNum;
						nextMoveX = currentPosX + movementXY[index1];
						nextMoveY = currentPosY + movementXY[index2];
					}
				}
			}
		}
	}
	
	if(counter != -1) {
		board.matrix[currentPosX][currentPosY] = counter;
		currentPosX = nextMoveX;
		currentPosY = nextMoveY;
	}
	return movesNum;
}
