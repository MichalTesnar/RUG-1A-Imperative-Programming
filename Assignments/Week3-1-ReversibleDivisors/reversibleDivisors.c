/*
 * reversibleDivisors.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 * 
 * This program is 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, d; //range definition, divisor
	scanf("%i %i %i", &a, &b, &d);
	
	int lastDigit = 0; //last digit of the manipulated number
	int reverse = 0; //reverse number to given number
	int counter = 0; //counts numbers which satisfy the condition
	
	int i=0; //iterable
	
	if(a%d==0){
		i=a;
	} else if((a/d)*d<a){
		i=(a/d+1)*d;
	}
	
	for(i=i;i<=b;i+=d){
		reverse = 0;
		a = i;
		
		while(a!=0){
			lastDigit=a%10;
			reverse = reverse*10+lastDigit;
			a=a/10;
		}
		
		//printf("%i %i\n", i, reverse);
		
		if(d!=0 && i%d==0 && reverse%d==0){
			counter++;
			//printf("YES");
		}
		
	}
	
	printf("%i\n", counter);
	
	return 0;
}

