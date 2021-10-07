/*
 * file: smallestDivisors.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: For number on the input, the program returns the
 * n-th number in the series, where each next term is the smallest divisor
 * which is not a divisor of any other previous term of the sum of
 * the previous two numbers in the series.
 */

#define SIZE 187554 //size of array

#include <stdio.h>

//checks given number is in a part of array up to a given index
int wasUsed(int usedDivisors[SIZE], int number, int endIndex){
	for(int i = 0; i <= endIndex; i++){
		if(number == usedDivisors[i]){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char **argv){
	int n; //input variable
	scanf("%i", &n);
	
	int initialTerm = 1, followingTerm = 2; //first two terms of the series
	int usedDivisors[SIZE] = {initialTerm, followingTerm}; //array for already used divisors
	int endIndex = 1; //index up to which we have to check the divisors in the array
	
	if(n == 1 || n == 2){
		printf("%i", n);
		return 0;
	}
	
	//generate n-th number in the series
	for(int i = 1; i < n; i++){
		int newTerm = initialTerm + followingTerm;
		//go through the divisors and check whether they have already been used
		
		for(int j = 1; j <= newTerm; j++){
			//if you find one which was not used yet, add it, increase index and break cycle
			if(newTerm%j == 0 && wasUsed(usedDivisors, j, endIndex) == 0){
				newTerm = j;
				usedDivisors[endIndex + 1] = j;
				endIndex += 1;
				break;
			}
		}
		
		//update series
		initialTerm = followingTerm;
		followingTerm = newTerm;
		}
	
	printf("%i\n", initialTerm);
	return 0;
}
