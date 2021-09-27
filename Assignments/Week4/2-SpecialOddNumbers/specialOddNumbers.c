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

int main(int argc, char **argv)
{
	int n, m; //range
	scanf("%i %i", &n, &m);
	
	int prime = 1;
	int oddDigits = 1;
	int counter = 0;
	
	n = (n%2==0 ? n+1 : n);
	
	for(n; n<=m;n+=2){
		
		//prime check
		for(int i = 2; i*i<=n;i++){
			if(n%i==0){
				prime = 0;
			}
		}
		
		//odd digits check
		int manipulated = n;
		while(manipulated!=0){
			if(manipulated%2!=1){
				oddDigits = 0;
			}
			manipulated/=10;
		}
		
		//binary representation
		manipulated = n;
		int binary = 0;
		while(manipulated!=0){
			binary+=manipulated%2;
			manipulated/=2;
		}
		
		//printf("%i %i %i %i\n", n, prime, oddDigits, binary%2);
		
		if(prime == 1 && oddDigits == 1 && binary%2==1){
			counter++;
		}
		
		binary = 0;
		prime = 1;
		oddDigits = 1;
	}
	
	printf("%i\n", counter);
	
	return 0;
}

