#include <stdio.h>
#include <time.h>
#include "E101.h"

int DEBUG =1;

int main()
{
  printf(" Hello I'll prentend to work \n");
  init();
  
	int count = 0;
	int pix[320];   //set pixel array to 32 wide
	int wh[320];    //for white pixel array
	double err = 0.0;
	double nwp =0 ; //number of white pixels
	double scale = 2.0;
	double v_left = 0; // left motor
	double v_right = 0;  // right motor
	float kp = 0.5; //This is the PID, 'Proportionality'
	int proportional_signal =0;
	
	while(count < 8000)
	{
		take_picture();
		display_picture(1,0);
		
	}
	
}
