#include "cell.hpp"

cell::cell(int x, int y): x(x), y(y) {}
void cell::setX(int x){
  this->x =x;}
void cell::setY(int y){
  this->y =y;}

cell::cell():x(0),y(0){}

int & cell::getX() {
  return x; }
int & cell::getY() {
  return y; }
