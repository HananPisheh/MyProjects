//Draw with mouse 
//Hanan Pisheh
//Email: hanan.pishe@gmail.com
void setup() {
 size(600, 600);
 smooth();
 background(50);//any color between 0-255  or it can be RGB (R,G,B)
 }
 void draw() {
 //background(50); // if we dont want to draw and just want a circle on mouse
 fill(0,0,190);
 ellipse(mouseX, mouseY, 20, 20);   // you can change the circle's dimention by changing last numbers
 }
 
 

