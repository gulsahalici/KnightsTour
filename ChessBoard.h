#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#define BOARD_ROW_LEN 8
#define BOARD_COLUMN_LEN 8

class ChessBoard {
	public:
		int matrix[BOARD_ROW_LEN][BOARD_COLUMN_LEN];
		
		ChessBoard();
		void printChessboard();
};

#endif
