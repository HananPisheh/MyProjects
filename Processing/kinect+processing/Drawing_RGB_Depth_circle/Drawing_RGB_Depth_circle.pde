//Hanan pisheh
//finding closet obj 
//hanan.pishe@gmail.com

import SimpleOpenNI.*;
SimpleOpenNI kinect;

int closestValue;
int closestX;
int closestY;
float previousX;
float previousY;

void setup() {
  size(640*2, 480*2);
  kinect = new SimpleOpenNI(this);
  kinect.enableRGB();
  kinect.enableDepth();
  background(0);
}

void draw() {
  //background(0);
  closestValue=8000;  
  kinect.update();
  //depth array from kinect
  int[] depthValues = kinect.depthMap();
  for (int y=0; y<480; y++) {
    for (int x=0; x<640; x++) {
      //int reversedX=640-x-1;
      int i= x+ y*640 ;
      int currentDepthValue=depthValues[i];
      //closest withing the range
      if (currentDepthValue > 900 && currentDepthValue<closestValue) {
        //save it
        closestValue=currentDepthValue;
        closestX=x;
        closestY=y;
        //  println("h4h");
      }
    }
  }
  float interpolatedX=lerp(previousX,closestX,0.03);
  float interpolatedY=lerp(previousY,closestY,0.03);
  
  image(kinect.depthImage(), 640, 0);
  fill( 0,255, 255);
  ellipse(closestX+640,closestY,10,10);
  image(kinect.rgbImage(),0, 480);
  fill( 0,255, 255);
  ellipse(closestX,closestY+480,10,10);
  
  stroke( 0,255, 255); //color of pen!
  strokeWeight(3);
  line(previousX, previousY, interpolatedX, interpolatedY);
  stroke( 200,255, 0); //color of pen!
  strokeWeight(5);
  line(640*2-previousX, previousY+480, 640*2-interpolatedX, interpolatedY+480);
  //save the closest point as the new previous one
  previousX=interpolatedX;
  previousY=interpolatedY;
}  
void mousePressed() {
  //save("drawing.png");
  background(0);
  
}

