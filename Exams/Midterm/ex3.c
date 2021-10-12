#include <stdio.h>
#include <stdlib.h>

#define BIGPRIME 4652508

int primeArray[BIGPRIME]={0};

void sieve(){
    for(int i = 2; i * i <= BIGPRIME; i++){
        if(primeArray[i]==0){
            for(int j = 2; j <= BIGPRIME / i; j++){
                primeArray[i * j]=1;
            }
        }
    }
}

int nextPrimeOfPrime(int x){
    x+=2;
    while(primeArray[x]!=0){
        x+=2;
    }
    return x;
}

int nextLowerPrimeOfPrime(int x){
	if(x==3){
		return 2;
	}
    x-=2;
    while(primeArray[x]!=0){
        x-=2;
    }
    return x;
}


int main(int argc, char *argv[]) {

    int a, b;
    scanf("%i %i", &a, &b);
    
    int counter;

    sieve();
    /*
    if(a == b && primeArray[a]==0 && (nextLowerPrimeOfPrime(a)*nextPrimeOfPrime(a)) < a*a){
		printf("%i\n", 1);
		return 0;
	}
    */

    for(int i = a; i <= b; i++){
		//printf("%i %i %i %i\n", i, primeArray[i], nextLowerPrimeOfPrime(i), nextPrimeOfPrime(i));
		if(primeArray[i]==0 && (nextLowerPrimeOfPrime(i)*nextPrimeOfPrime(i)) < i*i){
			counter++;
		}
	}
	printf("%i\n", counter);
    return 0;
}
