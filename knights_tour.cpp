#include <iostream>
using namespace std;

#include "Chess.h"

int main(){
	
	int xx;
	int yy;
	//GET START POINTS (x,y)
	cout<<"Coordinate points can be: {0,1,2,3,4,5,6,7}"<<endl;
	cout<<"Please enter X coordinate for the starting point: ";
	cin>>xx;
	cout<<"Please enter Y coordinate for the starting point: ";
	cin>>yy;
	//SET START POINTS
	Chess object(xx,yy);

	int counter=1;
	object.chessBoard[object.x][object.y]=counter;
	int minMoves=100;
	
	// x-2 y-1, x-1 y-2
	// x+2 y-1, x+1 y-2
	// x+2 y+1, x+1 y+2
	// x-2 y+1, x-1 y+2
	
	int nextMoveX;
	int nextMoveY;
	int moveX;
	int moveY;
	
	while(counter<64){
	
		for(int index1=0; index1<4; index1++) 
		{
			moveX=object.array[index1];
			
			for(int index2=0; index2<4; index2++){
				
				if(object.array[index2]*object.array[index2]!=moveX*moveX){
					moveY=object.array[index2];
					
					if(object.countMoves(object.x+moveX,object.y+moveY)<minMoves){
			
						minMoves=object.countMoves(object.x+moveX,object.y+moveY);
						nextMoveX=object.x+moveX;
						nextMoveY=object.y+moveY;
						}
					}
				}
			}

		counter++;			
		object.chessBoard[nextMoveX][nextMoveY]=counter;

		minMoves=100;
		object.x=nextMoveX;
		object.y=nextMoveY;

		}

	object.printChessboard();

	return 0;
}
