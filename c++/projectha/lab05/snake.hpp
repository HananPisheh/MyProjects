#ifndef SNAKE
#define SNAKE

#include <iostream>
#include <vector>
#include "cell.hpp"

using namespace std;

class snake {
public:
    snake(int h, int w);
    ~snake();
  void addlength();
  int w,h;
  int snakesizeR();//{return snakesize;}
  void snakesizeS(int i);//{this->snakesize = i ; }
  int headR();//{return head;}
  int headS(int i);///{this-> head= i;}
  int tailS(int i);//{this-> tail= i;}
  int tailR();//{return tail;}
  cell snakeArrayR(int j);//{return snakeArray[j];}
  void setsnakeX(int x,int i);//{snakeArray[i].setX(x);}
  void setsnakeY(int y,int i);//{snakeArray[i].setY(y);}
  

private:
    cell * snakeArray;
    int head,tail;
  int snakesize; 
};

#endif
