
//Ball [] ballcollection = new Ball[200];
ArrayList ballcollection;
void setup() {
  size(600, 600);
  smooth();
  ballcollection=new ArrayList();
  Ball myball=new Ball(200,200);
  ballcollection .add(myball);
//  for (int i=0; i<ballcollection.length;i++) {
   // ballcollection[i]=new Ball(random(0, width), random(0, height));
  
//}
}
void draw() {

  background(0);
  Ball myball=(Ball) ballcollection.get(0);
  myball.run();
  // for (int i=0; i<ballcollection.length;i++) {
 // ballcollection[i].run();}
}




/*
void setup() {
 size(600, 600);
 smooth();
 }
 void draw() {
 background(0);
 for (int i=0; i<20; i=i+1) {
 for (int j=0; j<20; j++) {
 if (i<10) {
 drawEclipse(i*20, j*20, 255);
 }
 else if(i>=10 & i<=15){
 drawEclipse(i*20, j*20, 100);
 
 }
 else{
 drawEclipse(i*20, j*20, 45);
 fill(255,0,0);
 ellipse(i*20, j*20, 45,45);
 }
 }
 }
 }
 void drawEclipse(float x, float y, float r) {
 fill(0, 12, r);
 ellipse(x, y, 20, 20);
 }
 */
