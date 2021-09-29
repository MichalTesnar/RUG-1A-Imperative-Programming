/*
 * file: palindromicDivisors.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)>
 * 
 * Description: Program outputs the number of numbers in a given range
 * which have only one palindromic divisor.
 */

#include <stdio.h>

//checks if number is a palindrom
int isPalindrom(int j){
	int manipulated = j;
	int reverse = 0;

	while(manipulated != 0){
		reverse = reverse*10 + manipulated%10;
		manipulated /= 10;
		}
	
	if(reverse == j){
		return 1;
	}
	
	return 0;
}

int main(int argc, char **argv)
{
	int a, b; //input range
	scanf("%i %i", &a, &b);
	
	int amount = 0; //counts the amount of numbers which satisfy the condition

	//search range, check number of palindromic divisors
	for(int i = a; i <= b; i++){
		int counter = 0;
		
		for(int j = 1; j*j <= i; j++){
			
			if(i%j == 0 && isPalindrom(j) == 1){
				counter++;
			}
			
			if(i%j == 0 && isPalindrom(i/j) == 1 && i/j != 1){
				counter++;
			}
			
			//if the number of palindromic divisors is greater than 1, we do not have to count anymore
			if(counter > 1){
				break;
			}	
		}
		
		//if the number of palindromic divisors is 1, we increase the counter
		if(counter == 1){
			amount++;
		}
	}	
	
	printf("%i\n", amount);
	return 0;
}

