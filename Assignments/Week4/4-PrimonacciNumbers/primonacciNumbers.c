/*
 * file: primonacciNumbers.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)>
 * 
 * Description: <add here>
 */


#include <stdio.h>

int nextPrime(int x){
	int notPrime = 0;
	while(notPrime == 0){
		int i = 2;
		while(i*i<=x){
			if(x%i==0){	
				x++;
				i = 0;
				break;
			}
			i++;
		}
		if(i*i>x){
			notPrime = 1;
		}
	}
	return x;
}

int main(int argc, char **argv)
{
	int n = 0; //input
	scanf("%i", &n);
	
	//printf("%i\n", nextPrime(27));
	//printf("%i\n", nextPrime(15));
	//printf("%i\n", nextPrime(77));
	
	int lowerNumber = 2, higherNumber = 3;
	
	for(int i = 1; i<n; i++){
		int temporary = nextPrime(lowerNumber+higherNumber);
		lowerNumber = higherNumber;
		higherNumber = temporary;
		//printf("%i %i\n", lowerNumber, higherNumber);
	}
	
	
	printf("%i\n", higherNumber);
	
	return 0;
}

