#ifndef _CHESS_H_
#define _CHESS_H_
#define BOARD_ROW_LEN 8
#define BOARD_COLUMN_LEN 8

class Chess{
	public:
		int currentPosX;
		int currentPosY;
		int chessBoard[BOARD_ROW_LEN][BOARD_COLUMN_LEN];
		int movementXY[4]; //Number of knight movements
			
		Chess(int, int);
		
		int countMoves(int, int);
		
		void printChessboard();
	private:
		bool isConvenient(int, int);	
};

#endif
