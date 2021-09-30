/*
 * OddsAndEvens.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 * 
 * This program outputs if the given number has more even or odd digits,
 * or if it is in balance.
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int n = 0; //input variable
	int balance = 0; //we add even and substract odds
	int currentDigit = 0; //the digit we are working with in the input number
	
	scanf("%i", &n);
	
	/*
	 * We remove digits at the end of the number,
	 * so we need to check whether the number is not zero.
	 * We take the last digit of the number to variable and remove it.
	 * We look if it ood or even and increment corresponding variable.
	 * Repeat four time (because the maximum size is 4 digits.
	 */
	 
	if(n != 0){
		currentDigit = n%10;
		n = (n - currentDigit)/10;		
		balance = (currentDigit%2 == 0 ? balance+1 : balance-1);
		
	}
	if(n != 0){
		currentDigit = n%10;
		n = (n - currentDigit)/10;		
		balance = (currentDigit%2 == 0 ? balance+1 : balance-1);
		
	}
	if(n != 0){
		currentDigit = n%10;
		n = (n - currentDigit)/10;		
		balance = (currentDigit%2 == 0 ? balance+1 : balance-1);
		
	}
	if(n != 0){
		currentDigit = n%10;
		n = (n - currentDigit)/10;		
		balance = (currentDigit%2 == 0 ? balance+1 : balance-1);
		
	}
	
	
	//We return answer according to the balance.
	
	if(balance == 0){
		printf("BALANCED\n");
	} else if (balance < 0){
		printf("ODDS\n");
	} else {
		printf("EVENS\n");
	}
	
	return 0;
}

