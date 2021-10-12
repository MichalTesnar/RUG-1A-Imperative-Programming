/* Name:  Michal Tesnar, S4740556
 * Table: 00099911
 */

#include <stdio.h>
#include <stdlib.h>

int isPrime(int x){
	for(int i = 2; i*i<=x; i++){
		if(x%i == 0){
			return 0;
		}
	}
	return 1;
}

int nextPrime(int x){
	if(x < 2){
		return 2;
	}
	if(x == 2){
		return 3;
	}
	x+=2;
	while(isPrime(x)==0){
		x+=2;
	}
	return x;
}

int wasUsed(int x, int endIndex, int array[]){
	for(int i = 0; i < endIndex; i++){
		if(array[i] == x){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	
	int counter = 0;
	int a, b;
	int usedPrimes[1000]={0};
	
	scanf("%i %i", &a, &b);
	
	if(a == b && isPrime(a) && a!=1){
		printf("%i\n", 1);
		return 0;
	}
	
	int start = nextPrime(a-1);
	
	for(int i = start; i < b; i = nextPrime(i)){
		int sum = i;
		//printf("LEAD:%i\n ", i);
		
		int consecutivePrime = nextPrime(i);
		while(nextPrime(consecutivePrime) <= b && sum+consecutivePrime <= b && nextPrime(consecutivePrime)>a){
			sum+=consecutivePrime;
			if(isPrime(sum) && wasUsed(sum, counter, usedPrimes)==0){
				usedPrimes[counter] = sum;
				counter++;
				//printf("Here: %i %i %i\n", i, consecutivePrime, sum);
			}
			consecutivePrime = nextPrime(consecutivePrime);
		}
		
	}
	printf("%i\n", counter);
	return 0;
}
