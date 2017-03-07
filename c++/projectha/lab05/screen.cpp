//hanan sedaghat pisheh
//lab05
#include "screen.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

screen::screen(int h, int w):w(w),h(h){}



screen::~screen(){ //deleting 
  delete [] freeSpace;
  
  for (int i = 1; i < h+1; i++) {
  
    //delete [] ScreenArray[i][j];
      
    delete [] ScreenArray[i];
  }
  delete [] ScreenArray;

}



void screen::makefreespace(int h , int w){
  //this function makes a 2 dimetional array of free space
  freeSpace= new cell[w*h];
  freenum=(h*w)-1;
  int k=0;
   for (int i=1 ; i< h+1 ; i++ ){
    for(int j=1 ; j<w+1 ; j++){
    freeSpace[k].setX(i);
    freeSpace[k].setY(j);
    k=k+1;
    }
   }

   //printing
   // cout<<endl;    
   // for(int j=0 ; j<w*h ; j++)
   //cout<<setw(4)<<j<<" = " <<freeSpace[j].getX()<<"    " <<freeSpace[j].getY()<<endl;
   //cout<<endl<<endl;
   
}





void screen::ScreenArrayf( int h, int w){

  //this function make an original screen array 
   ScreenArray = new int*[h+2];
   for(int t=0 ; t<h+2 ; t++)
   ScreenArray[t]=new int[w+2];
   
   int k=0;
   for (int i=1; i< h+1 ; i++ ){
    for(int j=1 ; j<w+1 ; j++){
      ScreenArray[i][j]=k;
      k=k+1;
  }
    }
   for(int j=0 ; j<w+2 ;j++){
   ScreenArray[h+1][j]=-1;
   ScreenArray[0][j]=-1;
   }

    for(int j=1 ; j<h+1 ;j++){
     ScreenArray[j][0]=-1;
     ScreenArray[j][w+1]=-1;
   }
   
   // printing
   //cout << endl << endl;
   //for (int i=0; i< h+2 ; i++ ){
   // for(int  j=0 ; j< w+2 ;j++){
   // cout<< setw(4) << ScreenArray[i][j];
   //      }
   // cout<<endl;
    // } 
}




cell screen::getrandom(){ //this functio make a random position for munchie and add its value to grid as a -1 and make it unavailable
  //creating a monchy
  int randomnumber = rand() % (freenum + 1);
  //monchy position
  monchy.setX(freeSpace[randomnumber].getX());
  monchy.setY(freeSpace[randomnumber].getY());

  ScreenArray[monchy.getX()][monchy.getY()]=-1; 

  /* printing
  cout<<endl;
   cout<<"freenum = "<<freenum<<endl;
  cout<<"randomnumber = "<<randomnumber<<endl;
  

  cout<<endl;
  cout<<"monchy cordinator x= "<<monchy.getX() <<"monchy y cor = "<<monchy.getY();

  
  
  cout<<endl;  
  cout<<endl;
  
  cout<<"freepool = "<< endl;
  cout<<endl;
  for(int j=0 ; j<w*h ; j++)
  cout<<setw(4)<<j<<" = " <<freeSpace[j].getX()<<"    " <<freeSpace[j].getY()<<endl;
  cout<<endl<<endl;
  

    cout << endl << endl;
  cout<<"ScreenArray"<<endl;
  for (int i=0; i< h+2 ; i++ ){
  for(int  j=0 ; j< w+2 ;j++){
  cout<< setw(4) << ScreenArray[i][j];
   }
  cout<<endl;
  }
  */

  freeSpace[randomnumber]=freeSpace[freenum];

  //cout<<"freepool = freenum replacing "<< endl;
  //cout<<endl;
  //for(int j=0 ; j<w*h ; j++)
  // cout<<setw(4)<<j<<" = " <<freeSpace[j].getX()<<"    " <<freeSpace[j].getY()<<endl;
  //cout<<endl<<endl;



ScreenArray[freeSpace[freenum].getX()][freeSpace[freenum].getY()]=randomnumber;
 
//cout << endl << endl;
/// cout<<"ScreenArray   of replacing random number with last one filled"<<endl;
// for (int i=0; i< h+2 ; i++ ){
// for(int  j=0 ; j< w+2 ;j++){
//   cout<< setw(4) << ScreenArray[i][j];
// }
// cout<<endl;
//}
 
freenum--; 
}


cell screen::monchycor(){
  //  cout<<"returning the monchy cor";
  return monchy;
}



bool screen::isBlocked(int x, int y){
return ScreenArray[x][y]==-1;
}


void screen::snakeEnterfreepool(cell snake){
 freeSpace[ ScreenArray[snake.getX()][snake.getY()]]=freeSpace[freenum];
 freenum--;
 ScreenArray[snake.getX()][snake.getY()]=-1;
}


void screen::Exitfreepool(cell cel){
  freenum++;
  ScreenArray[cel.getX()][cel.getY()]=freenum;
 freeSpace[freenum]= cel;
}

cell* screen::debugFreeSpace() { return freeSpace; }

int screen::debugFreeSize() { return freenum; }
