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
	
	
	int i = 0, j = 0; //iterable variables
	int counter = 0; //count of possible budget combinations
	
	/*
	 * We list all the combinations for one first devices till we reach
	 * the buget, same for the second one and then we check if the rest
	 * is divisible by the price of the last one. 
	 */
	while(i*a <= n){
		while(j*b + i*a <= n){
			if((n- (i*a+ j*b))%c == 0){
					counter++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	
	printf("%i\n", counter);
	
	return 0;
}

