//Hanan Pishe code 
//Email: Hanan.pishe@gmail.com
//random colorfull circle shoooting everywhere :P
void setup(){
size(500,500);
smooth();
background(random(0,200),random(0,200),random(0,200));
}
void draw(){
fill(random(0,200),random(0,200),random(0,200));
float y=random(5,20);
ellipse(random(0,width),random(0,height),y,y);
}
