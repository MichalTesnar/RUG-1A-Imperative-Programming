/*
 * compellingNumbers.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 * 
 * This program prints out the number of compelling numbers in a range,
 * that is all that have more divisors then numbers in binary expression.
 */

#include <stdio.h>

int main(int argc, char **argv){
	int a, b; //range defining variables
	scanf("%i %i", &a, &b); 
	
	int binary = 1, divisors = 0; //numbers are in binary, divisors
	int powerTwo = 1; //variable which we multiply by two to get numbers in binary
	int counter = 0;
	
	for(int i = a; i <= b; i++){
		
		//find the number of digits needed to express in the number binary
		while(powerTwo*2 <= i){
			powerTwo *= 2;
			binary++;
		}
		
		//find the number of divisors
		for(int j = 1; j*j <= i; j++){
			if(i%j == 0 && (i/j) != j){
				divisors += 2;
			}
			
			if(i%j ==0 && (i/j) == j){
				divisors++;
			}
			
		}
		
		//compare if there are more divisors and increase the counter
		if(divisors > binary){
			counter++;
		}
		
		//reset counters
		binary = 1;
		divisors = 0;
		powerTwo = 1;
	}
	
	printf("%i\n", counter);
	
	return 0;
}
