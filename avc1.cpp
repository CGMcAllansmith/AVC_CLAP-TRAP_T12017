
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
  int v_left = 0; // left motor
  int v_right = 0;  // right motor
  
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
		nwp = 0;
		for ( int i = 0 ; i < 32 ;i++)
		{
			if(wh[i]==1)
			{
				err = err + (i-16);// calculate how far line is from the centre and
				nwp = nwp + 1;// how many white pixel are there
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
		err = err/nwp;
        double scale = 1.0;
        v_left = 120 + (int) (err*scale);  //base motor speed is 60 which should be approx 1.17V
        v_right = 120 - (int) (err*scale);
        set_motor(1,v_left);
        set_motor(2,v_right);
        
        printf("\n");
		printf("err=%f nwp=%f v_left=%d v_righ=%d\n",err,nwp,v_left,v_right);
		
		sleep1(1,0);
		count++;

	//	printf("count=%d ain=%d\n",count,ain);

    }
    
   // close_screen_stream();
	printf("After init() error=%f\n",err);
	printf("Again\n");
	
	return 0;
}
