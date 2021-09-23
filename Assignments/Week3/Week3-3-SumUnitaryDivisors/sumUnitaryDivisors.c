/*
 * sumUnitaryDivisors.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 * 
 * This program outputs number of unitary divisors for a given number n,
 * that is numbers d which have remainder zero while dividing it,
 * and do not have remainder zero while divinding n/d.
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	int n, counter = 0; //input number, counter of unitary divisors
	scanf("%i", &n);
	
	int unitary = 1; //bool to collect whether the variable is unitary divisor
	
	/*
	 * For all divisors check if they are unitary by dividing it
	 * and the product of it by dividing given number by 
	 * all the smaller numbers.
	 * We increase the counter by two because one divisor counts for
	 * two possible pairs e.g. (4,5) and (5,4) for 20.
	 */
	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			for(int j = 1; j <= i; j++){
				if(j != 1 && (n/i)%j == 0 && i%j == 0){
					unitary = 0;
				}
			}
			
			//if it is divisible by any, we will not increase the counter
			if(unitary == 1){
				counter+=2;
			}
			//reset the counter
			unitary = 1;
		}
	}
	
	printf("%i\n", counter);
	
	return 0;
}
