#include "cell.hpp"

class screen{
public:

  cell getrandom();
  void makefreespace(int h ,int w);
  void ScreenArrayf(int h ,int w);
  screen(int h, int w);
  ~screen();
  cell monchycor();
  void Exitfreepool(cell cel);
  void snakeEnterfreepool(cell snake);
  bool isBlocked(int x, int y);
  cell* debugFreeSpace();  // { return freeSpace; }
  int debugFreeSize();  // { return freenum; }
private:

  cell *freeSpace;
  int  w,h;  //user input width , height
  cell monchy;
  int **ScreenArray;
  int freenum;
  };
