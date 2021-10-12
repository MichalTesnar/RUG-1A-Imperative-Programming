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


int main(int argc, char *argv[]) {

    int input, gap = 0;
    scanf("%i", &input);

    sieve();

    int lowerPrime = 2, higherPrime = 3;

    while(gap<input){
        gap = higherPrime - lowerPrime;
        lowerPrime = higherPrime;
        higherPrime = nextPrimeOfPrime(higherPrime);
    }

    printf("%i-%i=%i\n", lowerPrime, lowerPrime-gap, gap);
    return 0;
}
