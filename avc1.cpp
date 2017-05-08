#include <stdio.h>
#include "E101.h"

int main()
{
  printf(" Hello\n");
  init();
  int count = 0;
  char pix[32];
  char wh[32];
  int err = 0;
  int nwp =0 ;
  
  while(count < 8000)
	{
		take_picture();
		display_picture(1,0);
		// get pixel values and  decide if pixels are white
		for ( int i = 0 ; i < 32 ;i++)
		{
			pix[i] = get_pixel(120,i*10,3);
			wh[i] = 0;
			if ( pix[i] > 90)
			{
				wh[i] = 1;
			}
		}
		// calculate how far line is from the centre and
		// how many white pixel are there
		err = 0;
		nwp = 0;
		for ( int i = 0 ; i < 32 ;i++)
		{
			if(wh[i]==1)
			{
				err = err + (i-16);
				nwp = nwp + 1;
			}
        }
		// print all arrays
		for ( int i = 0 ; i < 32 ;i++)
		{
			printf("%d ",pix[i]);
        }		
		printf("\n");
		for ( int i = 0 ; i < 32 ;i++)
		{
			printf("%d ",wh[i]);
        }		
		printf("\n");
		printf("err=%d nwp=%d\n",err,nwp);
		
		sleep1(1,0);
		count++;

	//	printf("count=%d ain=%d\n",count,ain);

    }
    
   // close_screen_stream();
	printf("After init() error=%d\n",err);
	printf("Again\n");
	
	return 0;
}
