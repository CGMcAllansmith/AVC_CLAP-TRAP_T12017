#include <stdio.h>
#include <time.h>
#include "E101.h"

int DEBUG =0;

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
	//float kp = 0.5; //This is the PID, 'Proportionality'
	//int proportional_signal =0;
	
	while(count < 8000)
	{
		take_picture();
		//display_picture(1,0);
		for ( int i = 0 ; i < 32 ;i++)
		{
			pix[i] = get_pixel(120,i*10,3);
			wh[i] = 0;
			if ( pix[i] > 120)// get pixel values and  decide if pixels are white
			{
				wh[i] = 1;
			}
		}
		
		
		err = 0.0;
		nwp = 0.0;
		for ( int i = 0 ; i < 32 ;i++)
		{
			if(wh[i]==1)
			{
				nwp = nwp + 1;// how many white pixel are there
				err = err + (i-16);// calculate how far line is from the centre and
			}
		}
		
		if (nwp>0)
        {
          err = err/nwp;
          v_left =  50 - (int)(err*scale);  //base motor speed is 60 which should be approx 1.17V
          v_right = 50 + (int)(err*scale);
          if(DEBUG){
		      printf("err=%f nwp=%d v_left=%d v_righ=%d\n",err,(int)nwp,(int)v_left,(int)v_right);
		  }
          set_motor(1,v_left);
          set_motor(2,v_right);
		} 
	  else {
          set_motor(1,-40);
          set_motor(2,-40);
          if(DEBUG){
			  printf("Back\n");
		  }
          //sleep1(0,500000);
		}
	  
	}
	return 0;
}
