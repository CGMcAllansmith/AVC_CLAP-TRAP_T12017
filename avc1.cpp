#include <stdio.h>
#include <time.h>
#include "E101.h"

int DEBUG =1;

int main()
{
  printf(" Hello\n");
  init();
  
  /*
  set_motor(1,30);
  set_motor(2,30);
  sleep1(5,0);
  set_motor(1,0);
  set_motor(2,0);
  
  return 0;*/
  
  int count = 0;
  int pix[32];   //set pixel array to 32 wide
  int wh[32];    //for white pixel array
  double err = 0.0;
  double nwp =0 ; //number of white pixels
  double scale = 2.0;
  double v_left = 0; // left motor
  double v_right = 0;  // right motor
//<<<<<<< HEAD
 // float kp = 0.5;
//=======
  float kp = 0.5; //This is the PID, 'Proportionality'
//>>>>>>> 962e19a9762cfa06e26e551f1233317d85d4e436
  int proportional_signal =0;
  
  
  while(count < 8000)
	{
		take_picture();
		display_picture(1,0);
		
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
//<<<<<<< HEAD
//				v_left = 30 + proportional_signal;  //base motor speed is 60 which should be approx 1.17V
				//v_right = 30 - proportional_signal;
//=======
				//v_left = 1 + proportional_signal;  //base motor speed is 60 which should be approx 1.17V
				//v_right = 1 - proportional_signal;
//>>>>>>> 962e19a9762cfa06e26e551f1233317d85d4e436
				//set_motor(1,v_left);
				//set_motor(2,v_right);
				//err = err/nwp; //not sure why but replaced it but *nwp above
			}
			else{
				//nwp = nwp ;// how many white pixel are there
				//err = err + (i-16)*nwp;// calculate how far line is from the centre and
				//proportional_signal = err*kp;
				//v_left = 30 - proportional_signal;  //base motor speed is 60 which should be approx 1.17V
				//v_right = 30 + proportional_signal;
				//set_motor(1,v_left);
				//set_motor(2,v_right);
			}
				
        }
//<<<<<<< HEAD
//<<<<<<< HEAD

        if (nwp>0)
        {
          err = err/nwp;
          double scale = 1.0;
          v_left =  50 + (int)(err*scale);  //base motor speed is 60 which should be approx 1.17V
          v_right = 50 - (int)(err*scale);
          if(DEBUG){
		      printf("err=%f nwp=%d v_left=%d v_righ=%d\n",err,(int)nwp,(int)v_left,(int)v_right);
		  }
          set_motor(1,v_left);
          set_motor(2,v_right);
	  } else {
          set_motor(1,-40);
          set_motor(2,-40);
          if(DEBUG){
			  printf("Back\n");
		  }
          sleep1(0,500000);
	  }
//=======
  
//>>>>>>> Carls_work
//=======
  
//>>>>>>> 962e19a9762cfa06e26e551f1233317d85d4e436
        
		// print all arrays
		//for ( int i = 0 ; i < 32 ;i++)
		//{printf("%d ",pix[i]);   }		
		//printf("\n");
//		for ( int i = 0 ; i < 32 ;i++)
	//	{
	//		printf("%d ",wh[i]);
     //   }		
	//	printf("\n");
		
	//	sleep1(1,0);
		count++;

	//	printf("count=%d ain=%d\n",count,ain);

    } // while()
    
   // close_screen_stream();
	printf("After init() error=%f\n",err);
	printf("Again\n");
	
	return 0;
}
