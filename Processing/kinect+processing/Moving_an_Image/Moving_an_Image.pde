//Hanan Pisheh
//Hanan.pishe@gmail.com
import SimpleOpenNI.*;
SimpleOpenNI kinect;

int closestValue;
int closestX;
int closestY;
float lastX;
float lastY;

//declaring x-y cordinates for the image
float imageX;
float imageY;
boolean imagemoving;
PImage image;
void setup() {
  size(640, 480);
  kinect=new SimpleOpenNI(this);
  kinect.enableDepth();
  imagemoving=true;
  image=loadImage("q.jpg");
  background(0);
}
void draw() { 
  closestValue =8000;
  kinect.update();
  int [] depthValues=kinect.depthMap();
  for (int y=0; y<480; y++) {
    for (int x=0; x<640; x++) {
      int reversedX=640-x-1;
      int i= reversedX+y*640;
      int currentDepthValue=depthValues[i];
      if (currentDepthValue > 610 && currentDepthValue<1525 && currentDepthValue < closestValue) {
        closestValue=currentDepthValue;
        closestX=x;
        closestY=y;
      }
    }
  }
  float interpolatedX=lerp(lastX, closestX, 0.3);
  float interpolatedY=lerp(lastY, closestY, 0.3);
  background(0);
  if (imagemoving) {
    imageX=interpolatedX;
    imageY=interpolatedY;
  }
  image(image, imageX, imageY);
  lastX=interpolatedX;
  lastY=interpolatedY;
}

void mousePressed() {


  imagemoving =!imagemoving;
}

