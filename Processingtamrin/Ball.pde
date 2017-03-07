
class Ball{
//GLOBAL VARIABLE
float x=0;
float y=0;
float speedx=2;
float speedy=5;

///CONSTRUCTION
Ball(float _x, float _y){
x=_x;
y=_y;


}
//FUNCTIONS

void run(){
display();
move();

bounce();
gravity();
}

void gravity(){
speedy = speedy + 0.02;
}

void bounce(){
if(x>width){
 speedx=speedx*-1;

}
if(x<0){
speedx=speedx*-1;

}
if(y>height){
speedy=speedy*-1;
}
if(y<0){
speedy=speedy*-1;
}

}



void move(){
x=x+speedx;
y=y+speedy;
}

void display(){

ellipse(x,y,20,20);

}





}
