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
  img=createImage(kinect.depthWidth(), kinect.depthHeight(), RGB);
}

void draw() {
  background(0);
  kinect.update();
  img.loadPixels();
  int[] depth=kinect.depthMap();
  for (int x=0; x<kinect.depthWidth();x++) {
    for (int y=0; y<kinect.depthHeight(); y++) {
      int offset = x+y*kinect.depthWidth();
      int d=depth[offset];
      if(d>300 && d<800){
      img.pixels[offset]=color(255,0,0);      
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

