#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
enum m_new{stop=0, LEFT,RIGHT,up,down
};
m_new dir;
int fruit_x=rand()%18;
int fruit_y=rand()%18;
int arz=20;
int toll=20;
int y=toll/2;
int x=arz/2;
bool gameover=false;
class Snake{
	public:
		int fruit_x,fruit_y,arz,toll,y,x,rowx[60],rowy[60],plus;
		int _rowx,_rowy,longx,longy,intel=0;
		bool gameover;
	void setup();	
	void map();
	void move();
	void cm();
	void plus_plus();
	void sleep(int sleep);
};
void Snake :: setup(){
		fruit_x=rand()%18;
		fruit_y=rand()%18;
		arz=20;
		toll=20;
		y=toll/2;
		x=arz/2;
		gameover=false;
		plus=1;
		
	}
void Snake::map(){
		
	system("cls");
	for(int i=0;i<arz;i++)
		cout<<"#";
	cout<<endl;
	for(int i=0;i<toll;i++){
		for(int j=0;j<arz;j++){
			if(j==0 || j==arz-2)
				cout<<"#";
			if(i==x && j==y)
				cout<<"O";
			else if(i==fruit_y && j==fruit_x)
				cout<<"F";
			else{
				bool print=false;
				for(int k=0;k<plus; k++){
					if(rowx[k]==i && rowy[k]==j){
						cout<<"o";
						print=true;
					}
					
				}
				if(!print){
					cout<<" ";
				}
			}
		}
		cout<<endl;
	}
	for(int i=0;i<arz;i++)
		cout<<"#";
cout<<endl;
cout<<"plz for stop game press (Q)"<<endl;
cout<<"intel:" <<intel;
}
void Snake::move()
	{
	if(_kbhit()){
		switch(_getch()){
		case 'a':
		dir=LEFT;
		break;
		case 's':
		dir=down;
		break;
		case 'w':
		dir=up;
		break;
		case 'd':
		dir=RIGHT;
		break;
		case 'q':
		dir=stop;
		break;
		}
	}

	switch(dir){
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	case up:
		x--;
		break;
	case down:
		x++;
		break;
	defalt:
		break;
	}
 }
void Snake::cm(){
		
	/*
	if(x>20 || x<-1 || y>18 || y<0)
		gameover=true;
	*/
	if(x==21)
		x=0;
	else if(x==-1)
		x=21;
	else if(y==18)
		y=0;
	else if(y==0)
		y=18;
	for(int i=0; i<plus; i++){
		if(rowx[i]==x && rowy[i]==y)
			gameover=true;
	}
	if(x==fruit_y && y==fruit_x){
		fruit_x=rand()%18;
		fruit_y=rand()%18;
		plus++;
		intel++;
		
	}

	}
void Snake::sleep(int sleep){
	Sleep(sleep);
} 	
void Snake::plus_plus(){
		_rowx=rowx[0];
		_rowy=rowy[0];
		rowx[0]=x;
		rowy[0]=y;
		for(int i=1;i<plus;i++){
			longx=rowx[i];
			longy=rowy[i];
			rowx[i]=_rowx;
			rowy[i]=_rowy;
			_rowx=longx;
			_rowy=longy;
		}
	}	
int main(int argc, char** argv){
	Snake snake;
	snake.setup();
	while(!gameover){
		snake.map();
		snake.move();
		snake.cm();
		snake.plus_plus();
		snake.sleep(105);
	}
	return 0;
}
