#include "Knight.h"
#include "ChessBoard.h"
#include <iostream>

using namespace std;

int main() {
	int startPosX;
	int startPosY;
	
	//GET START POINTS (x,y)
	cout << "Coordinate points can be: {0,1,2,3,4,5,6,7}" << endl;
	
	cout << "Please enter X coordinate for the starting point: ";
	cin >> startPosX;
	
	cout << "Please enter Y coordinate for the starting point: ";
	cin >> startPosY;
	
	int counter = 0;
	int minMoves = 100;
	
	//SET START POINTS
	Knight knight(startPosX, startPosY);
	knight.board.matrix[knight.currentPosX][knight.currentPosY] = counter;
	
	// x-2 y-1, x-1 y-2
	// x+2 y-1, x+1 y-2
	// x+2 y+1, x+1 y+2
	// x-2 y+1, x-1 y+2
	
	int nextMoveX;
	int nextMoveY;
	int moveX;
	int moveY;
	
	while(counter < 64) {
		for(int index1 = 0; index1 < 4; index1++) {
			moveX = knight.movementXY[index1];
			for(int index2 = 0; index2 < 4; index2++) {
				if(knight.movementXY[index2] * knight.movementXY[index2] != moveX * moveX) {
					moveY = knight.movementXY[index2];
					if(knight.countMoves(knight.currentPosX + moveX, knight.currentPosY + moveY) < minMoves) {			
						minMoves = knight.countMoves(knight.currentPosX + moveX, knight.currentPosY + moveY);
						nextMoveX = knight.currentPosX + moveX;
						nextMoveY = knight.currentPosY + moveY;
					}
				}
			}
		}
		counter++;			
		knight.board.matrix[knight.currentPosX][knight.currentPosY] = counter;
		
		minMoves = 100;
		knight.currentPosX = nextMoveX;
		knight.currentPosY = nextMoveY;
	}
	knight.board.printChessboard();

	return 0;
}
