#ifndef CELL
#define CELL
class cell {
public:


  cell();//:x(0),y(0){}
  cell(int x, int y);//: x(x), y(y) {}
  void setX(int x); //{this->x =x;}
  void setY(int y); //{this->y =y;}
  int &getX(); // { return x; }
  int &getY(); // { return y; }
  //void screen(int h, int w);
private:
  int x, y;
};
#endif
