#include <stdio.h>

int sumOfDigits(int x){
	int sum = 0;
	while(x!=0){
		sum+=x%10;
		x/=10;
		}
	return sum;
}

int productOfDigits(int x){
	int product = 1;
	while(x!=0){
		product*=x%10;
		x/=10;
		}
	return product;
}

int isPrime(int x){
	if(x==0 || x == 1){
		return 0;
	}
	
	if(x==2 || x ==3){
		return 1;
	}
	for(int i = 2; i*i<=x; i++){
		if(x%i == 0){
			return 0;
		}
	}
	return 1;
}

int isPerfectSquare(int x){
	if(x == 0){
		return 0;
		}
	int i = 1;
	while(i*i<x){
		i++;
	}
	if(i*i == x){
		return 1;
	}
	//printf("%i %i\n", i*i, x);
	return 0;
}

int main(int argc, char **argv)
{
   int a, b;
   scanf("%i %i", &a, &b);
   int counter = 0;

   for(int i = a; i <=b; i++){
	   int sum = sumOfDigits(i);
	   int product = productOfDigits(i);
		if(isPrime(sum) == 1 && isPerfectSquare(product) == 1){
			counter++;
		//printf("%i %i %i %i %i\n", i, sumOfDigits(i), productOfDigits(i), isPrime(sumOfDigits(i)), isPerfectSquare(productOfDigits(i)));

	}
   }
   
   printf("%i\n", counter);
}
