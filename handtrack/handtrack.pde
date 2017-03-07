import SimpleOpenNI.*;
PImage green,yellow,red,blue;
SimpleOpenNI kinectObject;
// kinect image
PImage kinectImage;
// vector position of hands tracked
ArrayList<PVector> handPositions;

color handColor;
//size of dot that will show tracked hand's position
int dotSize;
 
/*******************************************************************************
Creates kinect object and draw window.  Enables hand gesture and tracking.
Adds empty vector to vector array since hand id# starts at one.
*******************************************************************************/
void setup(){
  //create kinect object
 kinectObject = new SimpleOpenNI(this);
 green=loadImage("green.png");
 yellow=loadImage("yellow.png");
 red=loadImage("red.png");
 blue=loadImage("blue.png");
  // enable depthMap and RGB camera
 kinectObject.enableDepth();
 kinectObject.enableRGB();
 handColor = color(0,0,255);
 dotSize = 10;
 //create window the size of kinect resolution
 size(kinectObject.rgbWidth(),kinectObject.rgbHeight());
 
  // disable mirror image
  kinectObject.setMirror(true);
 
  // enable hands and gesture
  kinectObject.enableHand();
  kinectObject.startGesture(SimpleOpenNI.GESTURE_HAND_RAISE);
 
  // create a new array for position of hands
  handPositions = new ArrayList();
 
  // hand id # starts at one - fill zero index with blank vector
  PVector tempPos = new PVector(0,0,0);
  handPositions.add(0,tempPos);
 }//void setup()
 
/*******************************************************************************
Updates kinect image and draws to screen.  For each hand position tracked,
print out coordinates and draw ellipse on hand.
*******************************************************************************/
void draw(){
  // update the cam
  kinectObject.update();
 
  // get the kinect image from the RGB camera
  kinectImage = kinectObject.rgbImage();
  // display the image on the screen
  
 image(kinectImage,0,0);
 image(green,100,100);
 image(yellow,100,140);
 image(red,100,180);
 image(blue,100,220);
  // for each hand being tracked, display each hands vector postion
  for(int i=1;i<handPositions.size();i++){
    println("handPositions.size()= " + handPositions.size());
    //get the current ahnd's position
    PVector tempVector = handPositions.get(i);
    //print out current hand's id# and position
    println(" position: " + tempVector);
    // change draw color based on hand id# (since hand id# starts at one
    // get the previous color array index
    stroke(handColor);
    // fill the ellipse with the same color
    fill(handColor);
    // draw ellipse at x/y coordinates given ellipse size
    ellipse(tempVector.x,tempVector.y,dotSize,dotSize);
    if(tempVector.x<133 && tempVector.x>100 && tempVector.y>104 &&tempVector.y<134 ){
    handColor = color(0,255,0);
    }
    if(tempVector.x<133 && tempVector.x>100 && tempVector.y>140 &&tempVector.y<174 ){
    handColor = color(255,255,0);
    }
    if(tempVector.x<133 && tempVector.x>100 && tempVector.y>180 &&tempVector.y<214 ){
    handColor = color(255,0,0);
    }
    if(tempVector.x<133 && tempVector.x>100 && tempVector.y>220 &&tempVector.y<254 ){
    
  handColor = color(0,0,255);  
  }
  }//for(int i=0;i<handPositions.size();i++)
}//void draw()
 
/*******************************************************************************
When a new hand is found, print out hand id and add position to vector array
*******************************************************************************/
void onNewHand(SimpleOpenNI curContext,int handId,PVector pos){
  //print out new tracked hand id #
  println("new hand Id: " + handId);
  // add current position of hands to vector arraylist
  handPositions.add(1,pos);
}//void onNewHand(SimpleOpenNI curContext,int handId,PVector pos)
 
/*******************************************************************************
While hand is being tracked, update new vector coordinates.
*******************************************************************************/
void onTrackedHand(SimpleOpenNI curContext,int handId,PVector pos){
  // convert vector so that top left corner is (0,0)
  curContext.convertRealWorldToProjective(pos, pos);
  // update vector positions of hand in vector arraylist
  handPositions.set(1,pos);
}//void onTrackedHand(SimpleOpenNI curContext,int handId,PVector pos)
 
/*******************************************************************************
When tracked hand is lost then display hand of lost hand and remove
from vector array.
*******************************************************************************/
void onLostHand(SimpleOpenNI curContext,int handId){
  // print out that hand was lost
  println("hand lost - hand Id: " + handId);
  // remove hand vector from vector arraylist
  handPositions.remove(handId);
}//void onLostHand(SimpleOpenNI curContext,int handId)
 
/*******************************************************************************
When hand gesture is found, Start tracking hand then print out vector coodinates
of where hand was found and its hand id #.
*******************************************************************************/
void onCompletedGesture(SimpleOpenNI curContext,int gestureType, PVector pos){
  // initiate hand tracking and give hand id number starting to track
  int handId = kinectObject.startTrackingHand(pos);
  // print out hand is starting to track, what gesture used, and where it was found
  //println(" hand tracking - gestureType: " + gestureType + ", vector position: " + pos + " hand id: " + handId);
}//void onCompletedGesture(SimpleOpenNI curContext,int gestureType, PVector pos)
