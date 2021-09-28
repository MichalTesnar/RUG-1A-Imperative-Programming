/*
 * file: palindromicDivisors.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)>
 * 
 * Description: Program outputs the number of numbers in a given range
 * which have only one palindromic divisor.
 */


#include <stdio.h>

int isPalindrom(int j){
	int manipulated = j;
	int reverse = 0;
	while(manipulated!=0){
		reverse += manipulated%10;
		reverse *= 10;
		manipulated/=10;
		}
	reverse/=10;
	if(reverse==j){
		return 1;
	}
	
	return 0;
}

int main(int argc, char **argv)
{
	int a, b; //range
	
	scanf("%i %i", &a, &b);
	int amount = 0;

	for(int i = a;i<=b;i++){
		int counter = 0;
		for(int j=1; j*j<=i; j++){
			if(i%j==0 && isPalindrom(j)==1){
				counter++;
				
			}
			if(i%(i/j)==0 &&isPalindrom(i/j)==1 && j!=1){
				counter++;
				}
		}
		
		if(counter == 1){
			amount++;
		}
		//printf("%i %i\n", i, counter);
	}	
	
	printf("%i\n", amount);
	return 0;
}

