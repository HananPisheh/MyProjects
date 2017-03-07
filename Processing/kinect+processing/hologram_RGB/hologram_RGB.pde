import SimpleOpenNI.*;
SimpleOpenNI kinect;

void setup() {
  size(645, 625);
  kinect= new SimpleOpenNI(this);
  kinect.enableRGB();
}

void draw() {
  background(0);
  kinect.update();
  scale(0.35, 0.35);
  image(kinect.rgbImage(), 568, 1210);//height/2);
  translate(580, 530);
  rotate(1.55);
  image(kinect.rgbImage(), 30, 30);
  translate(1430, 50);
  rotate(-3.15);
  image(kinect.rgbImage(), 740, 700);
  translate(1400, 770);
  rotate(-1.55);
  image(kinect.rgbImage(), 90, 0);
}
/*
 void setup(){
 size(640,480);
 background(0);
 kinect= new SimpleOpenNI(this);
 kinect.enableRGB();
 }
 void draw(){
 kinect.update();
 pushMatrix();
 scale(-0.5,0.5);
 image(kinect.rgbImage(),-width,0);
 popMatrix();
 
 
 }
 */
