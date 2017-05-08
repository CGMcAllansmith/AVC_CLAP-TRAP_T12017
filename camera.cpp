#include <stdio.h>
#include <time.h>
#include "E101.h"

int main(){
	init();
	take_picture();
	display_picture(2,0);
	//Create the 3 pixel arrays, one for each line we have tracing along the picture.
	char pixels1[32];
	char pixels2[32];
	char pixels3[32];
	//Initialise the max/min values.
	int max = 0;
	int min = 256;
	//Initialise the values used in the calculation of light levels.
	int uncertainty = 0;
	
	int upperMax1 = 0;
	int lowerMax1 = 0;   //max-uncertainty;
	int upperMin1 = 0;   //min+uncertainty;
	int lowerMin1 = 0;
	
	int upperMax2 = 0;
	int lowerMax2 = 0;
	int upperMin2 = 0;
	int lowerMin2 = 0;
	
	int upperMax3 = 0;
	int lowerMax3 = 0;
	int upperMin3 = 0;
	int lowerMin3 = 0;
	
	
	
	
	for (int i = 0; i<32; i++) {
		int top = i*10;
		pixels1[i] = get_pixel(120, top, 3);
		pixels2[i] = get_pixel(130, top, 3);
		pixels3[i] = get_pixel(140, top, 3);
	}
	
	
	//Printing out the array to allow us to check the max/min values work.
	//FIRST PICTURE.
	for (int i = 0;  i<32; i++) {
		printf("%d\n", pixels1[i]);
		//Records the max/min values for the first array.
		if (max<pixels1[i]) {
			max = pixels1[i];
		}
		if (min>pixels1[i]) {
			min = pixels1[i];
		}
		//Calculate the range for max and min.
		uncertainty = (max-min)/4;
		upperMax1 = max;
		lowerMax1 = max-uncertainty;
		upperMin1 = min+uncertainty;
		lowerMin1 = min;
	}
	
	
	//Prints the max/min values for the sole purpose of confirming they work as intended.
	printf("\n");
	printf("%d\n", max);
	printf("\n");
	printf("%d\n", min);
	printf("\n");
	printf("\n");
	//Printing the array and the max/min values will not be needed when actually navigating the track, it is here so we can check our methods work correctly.
	
	//SECOND PICTURE.
	for (int i = 0;  i<32; i++) {
		printf("%d\n", pixels2[i]);
		//Records the max/min values for the second array.
		if (max<pixels2[i]) {
			max = pixels2[i];
		}
		if (min>pixels2[i]) {
			min = pixels2[i];
		}
		//Calculate the range for max and min.
				uncertainty = (max-min)/4;
				upperMax2 = max;
				lowerMax2 = max-uncertainty;
				upperMin2 = min+uncertainty;
				lowerMin2 = min;
	}
	
	
	printf("\n");
	
	
	//THIRD PICTURE.
	for (int i = 0;  i<32; i++) {
		printf("%d\n", pixels3[i]);
		//Records the max/min values for the third array.
		if (max<pixels3[i]) {
			max = pixels3[i];
		}
		if (min>pixels3[i]) {
			min = pixels3[i];
		}
		//Calculate the range for max and min.
				uncertainty = (max-min)/4;
				upperMax2 = max;
				lowerMax2 = max-uncertainty;
				upperMin2 = min+uncertainty;
				lowerMin2 = min;
	}
	
	return 0;
	}
