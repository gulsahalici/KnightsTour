#ifndef _CHESS_
#define _CHESS_
#include "Chess.h"

Chess::Chess(int _x, int _y){
	//Entered parameters checked for validity
	bool invalidX=true;
	bool invalidY=true;
	int validXY[8]={0,1,2,3,4,5,6,7};
	
	for(int a=0; a<8; a++){
		if(_x==validXY[a])
			invalidX=false;
		if(_y==validXY[a])
			invalidY=false;
	}
	
	if(invalidX==true){
		x=0;
		cout<<"The X coordinate of the starting point is assigned to 0 because of entered invalid value."<<endl;
	}
	else
		x=_x;
	if(invalidY==true){
		y=0;
		cout<<"The Y coordinate of the starting point is assigned to 0 because of entered invalid value."<<endl;
	}
	else
		y=_y;
		
	//Reset chessBoard
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			chessBoard[i][j]=-1;
		}
	}
	
}

bool Chess::isConvenient(int first, int second){
	//Check next move validty
	if(first>=0 && first<8 && second>=0 && second<8 && chessBoard[first][second]==-1)
		return true;
			
	else 
		return false;
		
		}
		
int Chess::countMoves(int axisX,int axisY){
	//Count moves 	
	int movesNum=0;
			
	if(isConvenient(axisX,axisY)){
		int moveX;
		int moveY;
					
		for(int index1=0; index1<4; index1++){
			
			moveX=array[index1];
			
			for(int index2=0; index2<4; index2++){
				
				if(array[index2]*array[index2]!=moveX*moveX){
							
					moveY=array[index2];
							
					if(isConvenient(axisX+moveX,axisY+moveY))
						movesNum++;
					}
				}
			}
		}
	else
		movesNum=100;
				
		return movesNum;
			
	}
	
void Chess::printChessboard(){
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout<<chessBoard[i][j]<<"   ";
		}
		cout<<endl;
	}
	
}
#endif
