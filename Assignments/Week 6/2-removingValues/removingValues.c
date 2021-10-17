/*
 * file: removingValues.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: Given the number of digits that we can remove, the size
 * of the array and the array itself, program computes the longest
 * increasing sequence in the array while not removing more than maximum
 * number of digits.
 */

#include <stdio.h>

/* Recursive function for the task, name is intentionally short to shorten
 * the function call, variable skips is how many times we can skip. */
int rec(int size, int array[], int skips, int counter, int max, int index, int lastNumber){
	//update the maximum value
	if(counter > max){
		max = counter;
	}
	//base case (reaching the end of array)
	if(index == size - 1){
		return max;
	}
	
	//if run out of skips
	if(skips == 0){
		//if next number is bigger than the last number, increase the counter and move one digit
		if(lastNumber < array[index + 1]){
			return rec(size, array, 0, counter + 1, max, index + 1, array[index + 1]);
		}
		//if next number is smaller or equal to the last number, reset counter and move on
		if(lastNumber >= array[index + 1]){
			return rec(size, array, 0, 1, max, index + 1, array[index + 1]);
		}		
	}
	
	//if we can skip, we return what returns higher result (skipping the value or not)
	int noSkip = 0; //return value of sequence with no skipping
	//if sequence is increasing, increase the counter, else skip it and reset the counter
	if(lastNumber < array[index + 1]){
		noSkip = rec(size, array, skips, counter + 1, max, index + 1, array[index + 1]);
	} else {
		noSkip = rec(size, array, skips, 1, max, index + 1, array[index + 1]);
	}	
	//variable for return value when we skip a digit
	int skip = rec(size, array, skips - 1, counter, max, index + 1, lastNumber);
	//return the higher value of the two
	return (skip > noSkip ? skip : noSkip);
}

int main(int argc, char **argv){
	//input number of possible skips and the size of the array
	int skips, size;
	scanf("%i %i", &skips, &size);
	//input the array
	int array[size];
	for(int i = 0; i < size; i++){
		scanf("%i", &array[i]);
	}
	
	//printing the return value of the recursive function
	printf("%i\n", rec(size, array, skips, 1, 1, 0, array[0]));
	return 0;
}
