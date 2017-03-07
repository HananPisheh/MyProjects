//Kinect and hologram
//Hanan Pisheh
//hanan.pishe@gmail.com
import SimpleOpenNI.*;
SimpleOpenNI kinect;
PImage img;
void setup() {
  size(645, 625);
  kinect= new SimpleOpenNI(this);
  kinect.enableDepth();
  kinect.enableRGB();
  kinect.alternativeViewPointDepthToImage();
  img=createImage(kinect.rgbWidth(), kinect.rgbHeight(), RGB);
}

void draw() {
  background(0);
  kinect.update();
  img.loadPixels();
  
  PImage rgbimg=kinect.rgbImage();
  int[] rang=rgbimg.pixels;
  
  int[] depth=kinect.depthMap();
  for (int x=0; x<kinect.rgbWidth();x++) {
    for (int y=0; y<kinect.rgbHeight(); y++) {
      int offset = x+y*kinect.rgbWidth();
      int d=depth[offset];
      //int c=rgbimg[offset];
      if(d>=400 && d<=1000){
      img.pixels[offset]=color(rang[offset]);      
      }else{
      img.pixels[offset]=color(0); 
      }
    }
  }


  img.updatePixels();
  scale(0.35, 0.35);
  image(img, 568, 1210);//height/2);
  translate(580, 530);
  rotate(1.55);
  image(img, 30, 30);
  translate(1430, 50);
  rotate(-3.15);
  image(img, 740, 700);
  translate(1400, 770);
  rotate(-1.55);
  image(img, 90, 0);
}
void mousePressed(){
int[] depthValues=kinect.depthMap();
int clickPosition = mouseX+(mouseY*640);
int millimeters=depthValues[clickPosition];
float inches=millimeters/25.4 ;
fill(255);
textSize(32);
println(millimeters , 70,70);
}
