/*
 * file: smallestDivisors.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: For number on the input, the program returns the
 * nth number in the series, where next term is the smallest divisor
 * which is not a divisor of any other previous term of the sum of
 * the previous two number in the series.
 */

#define SIZE 187554 

#include <stdio.h>

int wasUsed(int usedDivisors[SIZE], int number, int endIndex){
	for(int i = 0; i <= endIndex; i++){
		if(number == usedDivisors[i]){
			return 1;
		}
	}
	
	return 0;
}

//prints the values in an array
void printArray(int size, int array[size]){
	for(int i = 0; i < size; i++){
		printf("%i ", array[i]);
	}
}

int main(int argc, char **argv){
	
	int n; //input
	scanf("%i", &n);
	
	int usedDivisors[SIZE] = {1, 2};
	int endIndex = 1;
	
	int initialTerm = 1, followingTerm = 2; //first two terms of the series
	
	if(n == 1 || n == 2){
		printf("%i", n);
		return 0;
	}
	
	for(int i = 1; i < n; i++){
		int newTerm = initialTerm + followingTerm;
		//printf("%i", newTerm);
		
		for(int j = 1; j <= newTerm; j++){
			//printf("%i", j);
			if(newTerm%j==0 && wasUsed(usedDivisors, j, endIndex)==0){
				newTerm = j;
				usedDivisors[endIndex+1] = j;
				endIndex += 1;
				break;
			}
		}
		
		initialTerm = followingTerm;
		followingTerm = newTerm;
		//printArray(10, usedDivisors);
		//printf("%i\n", followingTerm);
		}
	
	printf("%i\n", initialTerm);
	return 0;
}

