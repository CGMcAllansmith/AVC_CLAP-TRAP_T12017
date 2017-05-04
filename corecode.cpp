#include <stdio.h>
#include <time.h>
#include "E101.h"

int main(){
	init();
	take_picture();
	display_picture(2,0);
	char pixels1[32];
	char pixels2[32];
	char pixels3[32];
	//Initialise the max min values.
	int max = 0;
	int min = 256;
	for (int i = 0; i<32; i++) {
		int top = i*10;
		pixels1[i] = get_pixel(120, top, 3);
		pixels2[i] = get_pixel(130, top, 3);
		pixels3[i] = get_pixel(140, top, 3);
	}
	for (int i = 0;  i<32; i++) {
		printf("%d\n", pixels1[i]);
	}
	printf("\n");
	for (int i = 0;  i<32; i++) {
		printf("%d\n", pixels2[i]);
	}
	printf("\n");
	for (int i = 0;  i<32; i++) {
		printf("%d\n", pixels3[i]);
	}
	return 0;
	}
