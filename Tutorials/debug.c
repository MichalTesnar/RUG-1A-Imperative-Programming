#include <stdio.h>

int uniquePrimeFactors(int number){
	if(number == 1){
		return 0;
	}
	for(int i = 2; i<=number; i++){
		if(number%i == 0 && (number%i)%i==0){
			return uniquePrimeFactors(number/i);
		}
		if(number%i == 0 && (number%i)%i!=0){
			return 1 + uniquePrimeFactors(number/i);
		}
	}
	return 0;
}

int main(int argc, char **argv){
	int i = uniquePrimeFactors(24);
	printf("%i\n", i);
	return 0;
}
