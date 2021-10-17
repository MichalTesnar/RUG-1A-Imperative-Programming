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

//recursive function for the task
int possibleSums(int array[], int ourSum, int targetSum, int index, int size){
	//base contition to end the recursion
	if(index == size){
		return (ourSum == targetSum); //return boolean whether we have found the taget sum
	}
	
	//recursively move one index and either add it or not
	return possibleSums(array, ourSum + array[index], targetSum, index + 1, size)
		+ possibleSums(array, ourSum, targetSum, index + 1, size);
}

int main(int argc, char **argv){
	//input
	int input;
	scanf("%i", &input);
	
	int divisors[24] = {1}; //array to hold divisors of a number except for itself
	int endIndex = 1; //index till which we have to check the array
	
	//search divisors
	for(int i = 2; i*i <= input; i++){
		//if we find divisor, we add it to the array and increase the endIndex
		if(input%i == 0){
			divisors[endIndex] = i;
			endIndex++;
			//if number is not square also add the unitary divisor
			if(i*i != input){
				divisors[endIndex] = input/i;
				endIndex++;
				}
		}
	}
	
	//print the result of the recursive function call
	printf("%i\n", possibleSums(divisors, 0, input, 0, endIndex));
	return 0;
}
