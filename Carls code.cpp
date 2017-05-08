
#include <stdio.h>
#include <time.h>
#include "E101.h"

int main()
{
	int err;
	int count = 0
	open_screen_streem()
	char pix[32] //32 testing points for array
	char wh[32] //array 0= black 1=white
	int err = o;
	
	
	while (count <8000)
	{
		take_picture();
		//update_screen();
		display_picture(1,0);
		for ( int i = 0 ; i <32:i++)
		{
			pix[i] = get_pixel(120,i*10,3);
			wh[i] = 0
			if (pix[1]>90) // make white arrays 1
				{
					wh[1] = 1;
					}
					
			if (wh[1] == 1)
			{
				err = err (i-16) //centre array
			}
			printf("%d \n", pix[1]);
		}
			
		count ++;
		printf("\n);
	}
	
