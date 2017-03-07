///looking at the pixels
import SimpleOpenNI.*;
SimpleOpenNI kinect;

void setup(){
size(640,480);//(640*2,480)
kinect= new SimpleOpenNI(this);
//kinect.enableDepth(); if we want to see the depth aswell
kinect.enableRGB();
}
void draw(){
kinect.update();
PImage depthImage = kinect.depthImage();
PImage rgbImage = kinect.rgbImage();

//image(depthImage,640,0);
image(rgbImage,0,0);
}
void mousePressed(){
color c =get(mouseX,mouseY);
println(" r: " + red(c) + " g: " + green(c) + " b: " +blue(c));
}
