#include "Knight.h"
#include "ChessBoard.h"
#include <iostream>
#include <cstdlib>

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

	//SET START POINTS
	Knight knight(startPosX, startPosY);
	knight.board.matrix[knight.currentPosX][knight.currentPosY] = counter;
	
	while(counter <= 64) {
		knight.countOrMove(-1, -1, counter);
		counter++;
	}
	
	knight.board.printChessboard();

	return 0;
}
