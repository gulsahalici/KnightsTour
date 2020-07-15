#ifndef _CHESS_H_
#define _CHESS_H_

class Chess{
	public:
		int x;
		int y;
		int chessBoard[8][8];
		int array[4]={-2,-1,1,2};
			
		Chess(int,int);
		
		bool isConvenient(int,int);
		
		int countMoves(int,int);
		
		void printChessboard();
		
		
};

#include "Chess.cpp"
#endif
