/*
 * file: sumOfDivisors.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: Program prints out the number of possibilities how
 * a given number can be expressed as a sum of its own divisors
 * (except for itself) using each number no more than once.
 */

#include <stdio.h>

//prints the array for control
void printArray(int array[], int size){	
	for(int i = 0; i < size; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
}

//recursive function to calculate all the possible sums in the array
int possibleSums(int array[], int ourSum, int targetSum, int index, int size){
	if(index>size){
		return (ourSum == targetSum);
	}
	return possibleSums(array, ourSum + array[index], targetSum, index+1, size) +
		possibleSums(array, ourSum, targetSum, index+1, size);
}

int main(int argc, char **argv){
	
	int input, divisors[24]={1}, endIndex = 1;
	scanf("%i", &input);
	
	for(int i = 2; i*i <= input; i++){
		if(input%i==0){
			divisors[endIndex] = i;
			endIndex++;
			if(i*i!=input){
				divisors[endIndex] = input/i;
				endIndex++;
				}
		}
	}
	
	//printArray(divisors, endIndex);
	
	printf("%i\n", possibleSums(divisors, 0, input, 0, endIndex)/2);
	
	return 0;
}

