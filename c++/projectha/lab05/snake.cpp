//hanan sedaghat pisheh
//lab05
#include "snake.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

snake::snake(int h, int w)
{
  //making the first snake with width of 8 and in middle of the grid  
    snakeArray=new cell[w*h];
    head=8;
    tail=0;


    for(int a=0; a<9 ;a++){
      snakeArray[a].setX(h/2);
      snakeArray[a].setY((w/2)+a-4);
    }
    snakesize=8; //default snake size
   //printing snake value
   //    for(int j=0 ; j<w*h ; j++){
   // cout <<snakeArray[j].getX()<<snakeArray[j].getY()<<endl;
   //cout<<endl<<endl;
   // }   
}
snake::~snake() //delete snake
{
  delete snakeArray;
}

void snake::addlength(){ // make a circular array 

if (head==w*h)
    head=(head+1)% (w*h);
if (tail==w*h)
    tail=(tail+1)% (w*h);
}

int snake::snakesizeR(){return snakesize;}
void snake::snakesizeS(int i){this->snakesize = i ; }
int snake::headR(){return head;}
int snake::headS(int i){this-> head= i;}
int snake::tailS(int i){this-> tail= i;}
int snake::tailR(){return tail;}
cell snake::snakeArrayR(int j){return snakeArray[j];}
void snake::setsnakeX(int x,int i){snakeArray[i].setX(x);}
void snake::setsnakeY(int y,int i){snakeArray[i].setY(y);}
