#include "Chess.h"
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
	
	int counter = 1;
	int minMoves = 100;
	
	//SET START POINTS
	Chess chess(startPosX, startPosY);
	
	chess.chessBoard[chess.currentPosX][chess.currentPosY] = counter;

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
			moveX = chess.movementXY[index1];
			for(int index2 = 0; index2 < 4; index2++) {
				if(chess.movementXY[index2] * chess.movementXY[index2] != moveX * moveX) {
					moveY = chess.movementXY[index2];
					if(chess.countMoves(chess.currentPosX + moveX, chess.currentPosY + moveY) < minMoves) {			
						minMoves = chess.countMoves(chess.currentPosX + moveX, chess.currentPosY + moveY);
						nextMoveX = chess.currentPosX + moveX;
						nextMoveY = chess.currentPosY + moveY;
					}
				}
			}
		}
		counter++;			
		chess.chessBoard[nextMoveX][nextMoveY] = counter;
		
		minMoves = 100;
		chess.currentPosX = nextMoveX;
		chess.currentPosY = nextMoveY;
	}
	chess.printChessboard();

	return 0;
}
