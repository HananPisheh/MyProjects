//Hanan pisheh
//finding closet obj 
//hanan.pishe@gmail.com

import SimpleOpenNI.*;
SimpleOpenNI kinect;

int closestValue;
int closestX;
int closestY;

void setup() {
  size(640, 480);
  kinect = new SimpleOpenNI(this);
  kinect.enableRGB();
  kinect.enableDepth();
}

void draw() {
  closestValue=3000;  
  kinect.update();
  //depth array from kinect
  int[] depthValues = kinect.depthMap();

  for (int y=0; y<480; y++) {
    for (int x=0; x<640; x++) {
      int i= x+ (y*640) ;
      int currentDepthValue=depthValues[i];

      if (currentDepthValue > 0 && currentDepthValue<closestValue) {
        //save it
        closestValue=currentDepthValue;
        closestX=x;
        closestY=y;
      }
    }
  }
  image(kinect.rgbImage(), 0, 0);
  //image(kinect.depthImage(), 0, 0);
  fill(0, 255, 0);
  ellipse(closestX, closestY, 25, 25);
}  

