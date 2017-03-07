//Hanan Sedaghat pisheh
//lab05
#include <iostream>
#include <curses.h>
#include "getChar.hpp"
#include "screen.hpp"
#include <string>
#include <sstream>
#include <cstdlib>
#include "snake.hpp"

using namespace std;
bool gameover=false;
int rrand(screen * wor);
void startup( void );

int main() {
int h,w, munchievalue;
 bool debug = true;//false;
cout<<"please inter height value (9-25) : "<< endl;
cin>>h;
cout<<"please inter width value (9-80): "<< endl;
cin>>w;
screen *worm =new screen(h,w);
snake *s = new snake(h,w);
  
worm->makefreespace(h,w);
worm->ScreenArrayf(h,w);

    //draw wall
    startup();
    move(0, 0);  // move the curser to the top- and left-most block.
    for (int i=0; i<w+2 ;i++)
    addstr("*");
    for (int y=1; y<h+2 ; y++){
    move(y, 0);
    addstr("*");
    move(y,w+1);
    addstr("*");
    }
    for (int k=1; k<w+2 ;k++){
    move(h+1, k);
    addstr("*");
     }
    
    
    
    //draw first worm
    for(int j=s->tailR(); j< s->headR();j++){
     move(s->snakeArrayR(j).getX(),s->snakeArrayR(j).getY());
     addstr("o");
     worm->snakeEnterfreepool(s->snakeArrayR(j));
    }
    
    move(s->snakeArrayR(s->headR()).getX(),s->snakeArrayR(s->headR()).getY());
    addstr("@");
   
    
    
    
    
    //add position of snake to freepool
    worm->snakeEnterfreepool(s->snakeArrayR(s->headR()));
    
    //make random munchie
   munchievalue= rrand(worm);
   refresh();
   
    
    int score=0;
    move(0,1);
    addstr("worm ");
    move(0,w-7);
    addstr("score= ");
    addstr(std::to_string(score).c_str());
    refresh(); 

   //getch(); // wait for input
    char input = get_char();
    while( input == ' ' )
      input = get_char();
    char pinput=input;
    // getch(); // wait for input
    while (!gameover) {
     
    int deltaX = 0;
    int deltaY = 0;
     
    refresh();
      //   getch(); // wait for input
       input = get_char();     
      if (input == 'k')
	{
	  deltaX = -1;
	  pinput=input;
	}
      else if(input == 'l')
	{
	  deltaY = 1;
	  pinput=input;
	}
      else if(input == 'h')
	{
	  deltaY = -1;
	  pinput=input;
	}
      else if(input == 'j')
	{
	  deltaX = 1;
	  pinput=input;
	}
        
      else
	{
	   input= get_char();
	  //int deltaX = 0;
	  //int deltaY = 0;
	  // break;
	   continue;
	}
      
    int newX = s->snakeArrayR(s->headR()).getX()+deltaX;
    int newY = s->snakeArrayR(s->headR()).getY()+deltaY;
    int mX = worm->monchycor().getX();
    int mY = worm->monchycor().getY();
    
        
    //if worm see -1 value in screen array determine if its wall or itself or monchie
    bool ateMunchie = false;

      if(newX == mX && newY == mY)
	{
	  ateMunchie = true;
	}
      else if (worm->isBlocked(newX, newY))
	{
	  gameover = true;
	  //delete worm;
	  //delete s;
	  continue;
	}
        
        
        
        
    move(s->snakeArrayR(s->headR()).getX(),s->snakeArrayR(s->headR()).getY());
    addstr("o");
    refresh();
   input = get_char();
    s->setsnakeX(newX,s->headR()+1);
    s->setsnakeY(newY,s->headR()+1);
    s->headS(s->headR()+1);
	
	
	move(s->snakeArrayR(s->headR()).getX(),s->snakeArrayR(s->headR()).getY());
	addstr("@");
	worm->snakeEnterfreepool(s->snakeArrayR(s->headR()));
	refresh();
	
	move(s->snakeArrayR(s->tailR()).getX(),s->snakeArrayR(s->tailR()).getY());     
    addstr(" ");
	worm->Exitfreepool(s->snakeArrayR(s->tailR()));
    refresh();
    s->tailS(s->tailR()+1);
	 
	//refresh();
	// s->addlength();
	
	if (ateMunchie){	
    worm->Exitfreepool(worm->monchycor());
	int temptail=s->tailR();
	s->tailS(s->tailR()-munchievalue);
	for(int t=s->tailR() ; t<temptail; t++ ){
    worm->snakeEnterfreepool(s->snakeArrayR(t));}
    // s->addlength();}
	score=score+munchievalue;
	move(0,w-7);
	addstr("score= ");
	addstr(std::to_string(score).c_str());
	munchievalue = rrand(worm);
    refresh();
	}
	
    if (debug)
	  {
	    for(int i = 0; i < worm->debugFreeSize(); ++i)
	      {
		cell c = worm->debugFreeSpace()[i];
		move(c.getX(), c.getY());
		addstr(".");
	      }
	    move(worm->monchycor().getX(), worm->monchycor().getY());
	    addstr("M");
	    for (int i = s->tailR(); i != s->headR(); i = (i + 1) % (w * h))
	      {
		cell c = s->snakeArrayR(i);
		move(c.getX(), c.getY());
		addstr("S");
	      }
	    refresh();
	  }
	 }
    endwin();
    //     erminate();
}


  void startup( void )
  {
    initscr();  // activate the curses
    curs_set(0); // do not display the cursor
    clear();    // clear the screen that curses provides
    noecho();   // prevent the input chars to be echoed to the screen
    cbreak();   // change the stty so that characters are delivered to the program as they are typed--no need to hit the return key!
}
void erminate( void )
{
  //  mvcur( 0, COLS - 1, LINES - 1, 0 );
  //clear();
  refresh();
  endwin();
}



//make random number

int rrand(screen * wor){
  wor->getrandom();
  srand(time(NULL));
  int randshow= rand()%9+1;
  //char str[2];
  //sprintf(str,"%d", randshow);
  //  str[1] = '\0';
  move(wor->monchycor().getX(),wor-> monchycor().getY());
  // addstr(str);
  addstr(std::to_string(randshow).c_str());
  refresh();
  return randshow;

}
