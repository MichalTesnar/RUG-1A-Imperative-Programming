/*
 * productDivisors.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int n, product=1; //input variable, variable to calculate the product of the digits
	
	scanf("%d",&n);
	
	int manipulated = n; //variable from which we will remove digits
	
	/*
	* Check if the manipulated number is not zero.
	* If the last digit is not zero, multiply the product by it,
	* remove the last digit.
	* Repeat four times, because the maximum size is 4 digits.
	*/
	
	if(manipulated!=0){
		product *= manipulated%10;
		manipulated = manipulated/10;
	}
	
	if(manipulated!=0){
		product *= manipulated%10;
		manipulated = manipulated/10;
	}
	
	if(manipulated!=0){
		product *= manipulated%10;
		manipulated = manipulated/10;
	}
	
	if(manipulated!=0){
		product *= manipulated%10;
		manipulated = manipulated/10;
	}
	
	/* 
	 * Check if the input is divisible by the calculated
	 * and if the product is not zero,
	 * and answer either YES or NO.
	 */
	 
	if(product != 0 && n%product==0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	return 0;
}

