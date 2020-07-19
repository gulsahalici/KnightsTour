#ifndef CHESSBOARD
#define CHESSBOARD
#include "ChessBoard.h"
#include <iostream>

using namespace std;

ChessBoard::ChessBoard() {
	//Reset matrix
	for(int row = 0; row < BOARD_ROW_LEN; row++) {
		for(int column = 0; column < BOARD_COLUMN_LEN; column++) {
			matrix[row][column] = -1;
		}
	}
}

void ChessBoard::printChessboard() {
	for(int row = 0; row < BOARD_ROW_LEN; row++) {
		for(int column = 0; column < BOARD_COLUMN_LEN; column++) {
			cout << matrix[row][column] << "   ";
		}
		cout << endl;
	}
}

#endif
