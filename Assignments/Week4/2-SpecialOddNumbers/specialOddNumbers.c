/*
 * file: specialOddNumbers.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)>
 * 
 * Description: Program finds number of integers in a given range,
 * which are prime, have only odd digits and have an odd number
 * of ones in its binary representation.
 */


#include <stdio.h>

int isPrime(int n){
	for(int i = 2; i*i<=n;i++){
			if(n%i==0){
				return 0;
			}
		}
	return 1;
}

int oddDigits(int n){
	int manipulated = n;
		while(manipulated!=0){
			if(manipulated%2!=1){
				return 0;
			}
			manipulated/=10;
		}
	return 1;
}

int onesInBinary(int n){
	int manipulated = n;
		int binary = 0;
		while(manipulated!=0){
			binary+=manipulated%2;
			manipulated/=2;
		}
	return binary;
}

int main(int argc, char **argv)
{
	int n, m; //range
	scanf("%i %i", &n, &m);
	int counter = 0;
	
	n = (n%2==0 ? n+1 : n);
	
	for(n; n<=m;n+=2){
		if(isPrime(n) == 1 && oddDigits(n) == 1 && onesInBinary(n)%2==1){
			counter++;
		}
	}
	printf("%i\n", counter);
	
	return 0;
}

