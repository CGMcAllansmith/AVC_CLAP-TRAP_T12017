#include <stdio.h>
#include <time.h>
#include "E101.h"

int main()
{
  printf(" Hello\n");
  init();
  int count = 0;
  char pix[32];   //set pixel array to 32 wide
  char wh[32];    //for white pixel array
  double err = 0.0;
  double nwp =0 ; //number of white pixels
  double v_left = 0; // left motor
  double v_right = 0;  // right motor
  float kp = 0.5;
  int proportional_signal =0;
  
  
  while(count < 8000)
	{
		take_picture();
		display_picture(0,0);
		
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
				err = err + (i-16)*nwp;// calculate how far line is from the centre and
				proportional_signal = err*kp;
        //double scale = 1.0;
				v_left = 30 + proportional_signal;  //base motor speed is 60 which should be approx 1.17V
				v_right = 30 - proportional_signal;
				set_motor(1,v_left);
				set_motor(2,v_right);
				//err = err/nwp; //not sure why but replaced it but *nwp above
			}
			else{
				nwp = nwp ;// how many white pixel are there
				err = err + (i-16)*nwp;// calculate how far line is from the centre and
				proportional_signal = err*kp;
				v_left = 30 - proportional_signal;  //base motor speed is 60 which should be approx 1.17V
				v_right = 30 + proportional_signal;
				set_motor(1,v_left);
				set_motor(2,v_right);
			}
				
        }
  
        
		// print all arrays
		//for ( int i = 0 ; i < 32 ;i++)
		//{printf("%d ",pix[i]);   }		
		//printf("\n");
		for ( int i = 0 ; i < 32 ;i++)
		{
			printf("%d ",wh[i]);
        }		
		printf("\n");
		printf("err=%f nwp=%d v_left=%d v_righ=%d\n",err,(int)nwp,(int)v_left,(int)v_right);
		
		sleep1(1,0);
		count++;

	//	printf("count=%d ain=%d\n",count,ain);

    }
    
   // close_screen_stream();
	printf("After init() error=%f\n",err);
	printf("Again\n");
	
	return 0;
}
