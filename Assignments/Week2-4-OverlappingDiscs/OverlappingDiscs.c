/*
 * OverlappingDiscs.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//variables which describe the three circles
	int centerX1, centerY1, radius1;
	int centerX2, centerY2, radius2;
	int centerX3, centerY3, radius3;
	
	//input of all variables
	scanf("%i %i %i", &centerX1, &centerY1, &radius1);
	scanf("%i %i %i", &centerX2, &centerY2, &radius2);
	scanf("%i %i %i", &centerX3, &centerY3, &radius3);
	
	//variables describing whether a circle is overlaping with another one
	int overlap1=0, overlap2=0, overlap3=0;
	
	/*
	 * We calculate the distance between two centers of circles
	 * and compare whether it is smaller then the sum of the two
	 * corresponding radii.
	 * If it is, we change the corresponding variable which denotes
	 * whether a circle overlaps with another one to 1.
	 */
	 
	if((centerX1-centerX2)*(centerX1-centerX2)+(centerY1-centerY2)*(centerY1-centerY2)<(radius1+radius2)*(radius1+radius2)){
		overlap1=1;
		overlap2=1;
	}
	
	if((centerX1-centerX3)*(centerX1-centerX3)+(centerY1-centerY3)*(centerY1-centerY3)<(radius1+radius3)*(radius1+radius3)){
		overlap1=1;
		overlap3=1;
	}
	
	if((centerX3-centerX2)*(centerX3-centerX2)+(centerY3-centerY2)*(centerY3-centerY2)<(radius3+radius2)*(radius3+radius2)){
		overlap2=1;
		overlap3=1;
	}
	
	//We answer the sum of all circles that have some overlap with another one.
	printf("%i\n", overlap1+overlap2+overlap3);
	
	return 0;
}

