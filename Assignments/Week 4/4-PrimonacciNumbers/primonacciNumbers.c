/*
 * file: primonacciNumbers.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: This program takes an input n and returns corresponding
 * item in Primonacci series, where each next item the smallest or equal
 * next prime to the sum of the two preceeding items.
 */

#include <stdio.h>

//checks if given number is a prime
int isPrime(int n){
	for(int i = 2; i*i<= n; i++){
			if(n%i == 0){
				return 0;
			}
		}
	return 1;
}

//if given number is not a prime, then returns next prime after that given number
int nextPrime(int x){
	int notPrime = 1;
	while(notPrime == 1){
		if(isPrime(x) == 1){
			notPrime = 0;
			break;
		}
		x++;
	}
	return x;
}

int main(int argc, char **argv){
	int n = 0; //input variable
	scanf("%i", &n);
	
	int lowerNumber = 2, higherNumber = 3; //setup start of the series
	
	//calculating the next items in the series
	for(int i = 1; i<n; i++){
		int temporary = nextPrime(lowerNumber + higherNumber);
		lowerNumber = higherNumber;
		higherNumber = temporary;
	}
	
	printf("%i\n", higherNumber);
	
	return 0;
}

