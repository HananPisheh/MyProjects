//Hanan pisheh
//finding closet obj 
//hanan.pishe@gmail.com

import SimpleOpenNI.*;
SimpleOpenNI kinect;
PImage img;

void setup() {
  size(640, 480);
  kinect = new SimpleOpenNI(this);
  kinect.enableRGB();
  kinect.enableDepth();
  img=createImage(kinect.depthWidth(), kinect.depthHeight(), RGB);
}

void draw() {
  kinect.update();
  background(0);
  img.loadPixels();

  int[] depth=kinect.depthMap();
  for (int x=0; x<kinect.depthWidth (); x++) {
    for (int y=0; y<kinect.depthHeight (); y++) {
      int offset=x+y*kinect.depthWidth();
      int d=depth[offset];
      if(d>300 && d<700){
        img.pixels[offset]=color(255,0,150);
      }else{
        img.pixels[offset]=color(0);
        }
    }
  }
img.updatePixels();
image(img, 0, 0);
fill(255);
textSize(32);
text(mouseX+ "  " + mouseY ,10,64);

}
void mousePressed(){
int[] depth=kinect.depthMap();
int clickPosition = mouseX+(mouseY*640);
int millimeters=depth[clickPosition];
println("mm: "+ millimeters );
}



