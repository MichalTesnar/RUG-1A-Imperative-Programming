/*
 * electronicDevices.c
 * 
 * Program outputs all possible combinations of devices we can buy with a limited budget. 
 *
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, c, n; //variables for devices, budget
	scanf("%i %i %i %i", &a, &b, &c, &n);
	
	
	int i=0, j=0; //iterable variables
	int counter = 0;
	int solutionExists = 1;

	while(i*a<=n){
		while(j*b+i*a<=n){
			/*while(i*a+j*b+k*c<=n){
				if(i*a+j*b+k*c==n){
					//printf("%i %i %i\n", i, j, k);
					counter++;
				}
				k++;
			}*/
			
			if((n-(i*a+j*b))%c==0){
					//printf("%i %i\n", i, j);
					counter++;
				}
			
			j++;
			//k=0;
		}
		i++;
		j=0;
	}
	
	printf("%i\n", counter);
	
	return 0;
}

