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
	int n, counter=0; //input number, counter of unitary divisors
	scanf("%i", &n);
	
	int unitary = 1; //bool to collect whether the variable is unitary divisor
	
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			for(int j=1;j<=i;j++){
				if(j!=1 && (n/i)%j==0 && i%j==0){
					unitary=0;
					break;
				}
			}
			
			if(unitary == 1){
				counter++;
			}
			
			unitary = 1;
		}
	}
	
	printf("%i\n", 2*counter);
	return 0;
}

