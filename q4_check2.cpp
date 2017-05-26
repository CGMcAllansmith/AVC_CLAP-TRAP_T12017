#include <stdio.h>
#include <time.h>
#include "E101.h"



int DEBUG =0;


int count = 0;
	int pix[320];   //set pixel array to 32 wide
	int wh[320];    //for white pixel array
	double err = 0.0;
	double nwp =0 ; //number of white pixels
	double scale = 3;
	double v_left = 0; // left motor
	double v_right = 0;  // right motor
	//float kp = 0.5; //This is the PID, 'Proportionality'
	//int proportional_signal =0;
	//int revcount = 0;
	int bxleft[240];
	int boxright[240];
	int whleft[240];
	int whright[240];
	int tcount = 0;
	
	int readingPinL = 1; 	//The pin that the left IR sensor reads from
	int adc_readingL; 	 	//The value where the reading from the left IR sensor is stored
	
	int readingPinR  = 0; 	//The pin that the right IR sensor reads from
	int adc_readingR;		//The value where the reading from the right IR sensor is stored
	
	int readingPinF = 2;	//The pin where the front IR sensor reads from 
	int adc_readingF;		//The value where the reading from the front sensor is stored
	
	int quadrantfour = 0;
	int centred = 0;
	double wallscale = 9;
	double wallerror = 0;
	
void turn_left()
	{ // turn left 90*		
	set_motor(1,-70);
	set_motor(2,70);
	sleep1(1,000000);
		}
		
void curvy()
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
		
void reverse()
			{
			set_motor(1,-50);
			set_motor(2,-50);
			sleep1(0,500000);
			//revcount = revcount + 1;
          
			if(DEBUG){
			  printf("Back\n");
		  }
	  }

void Lreverse()
			{
			set_motor(1,-70);
			set_motor(2,50);
			sleep1(0,500000);
			//revcount = revcount + 1;
          
			if(DEBUG){
			  printf("Back and left\n");
		  }
	  }

void quadrantone()
			{
			 char addr[15]={'1','3','0','.','1','9','5','.','6','.','1','9','6'};
			 printf("addr = %s\n",addr);
			 connect_to_server(addr,1024);
			 char from_server[24];
			 char to_server[24] = {'P','l','e','a','s','e'};
			 send_to_server(to_server);	 
			 receive_from_server(from_server);
			 printf("received from server= %s\n",from_server);
			 for ( int i = 0 ; i< 6;i++)
			 {
			   to_server[i]=from_server[i];
			 }
			 to_server[6]='P';
			 to_server[7]='l';
			 to_server[8]='e';
			 to_server[9]='a';
			 to_server[10]='s';
			 to_server[11]='e';
			 to_server[12]= 0;
			 send_to_server(to_server);	 
				sleep1(1,000000);
				set_motor(1,70);
				set_motor(2,70);
				sleep1(1,000000);
			}
 


	
int main()
{
  printf(" Hello I'll prentend to work \n");
  init();
  
	//quadrantone();
	while(count < 8000)
	{
		take_picture();
		adc_readingL = read_analog(readingPinL); //This is where the actual readings of the IR sensors happens
		adc_readingR = read_analog(readingPinR);
		adc_readingF = read_analog(readingPinF); //turn on front IR
		
		if (adc_readingL > 400 && adc_readingR >400 )
		{
			quadrantfour = 1;
			printf("Q4 active\n");
		}
		while (quadrantfour == 1)
		{
			
			wallerror = 0.0;
			adc_readingL = read_analog(readingPinL); //This is where the actual readings of the IR sensors happens
			adc_readingR = read_analog(readingPinR);
			adc_readingF = read_analog(readingPinF); //turn on front IR
			centred = adc_readingL - adc_readingR;
			wallerror = centred/wallscale;
			v_left =  50 - (int)(wallerror);  //base motor speed is 60 which should be approx 1.17V
			v_right = 50 + (int)(wallerror);
			printf("Leftwall = %d , Rightwall = %d  frontwall = %d \n", adc_readingL , adc_readingR , adc_readingF);
			printf("centred = %d , wallerror = %d \n" , (int) centred , (int) wallerror);
			sleep1(3,0);
			set_motor(1,v_left);
			set_motor(2,v_right);
			
		}
		//display_picture(1,0);
		for ( int i = 0 ; i < 32 ;i++)
		{
			pix[i] = get_pixel(120,i*10,3);
			wh[i] = 0;
			if ( pix[i] > 100)// get pixel values and  decide if pixels are white
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
		
		
		if (nwp>0 && nwp<25)
        {
          //curvy();
		}  
		else if (nwp>25)
		{
			if (tcount > 0 && tcount < 2)
			{
				tcount = tcount +1;
				sleep1(0,500000);
				scale = 4;
				printf("I'm a good robot and made it past Q2\n");
				}
			else {
				//Lreverse();
			}
			
			}
		
		else {
          //reverse();
		  }
          //sleep1(0,500000);
		}
	  
	  //turn_left();
	  
	
	return 0;
}
