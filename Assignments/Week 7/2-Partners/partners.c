/*
 * file: partners.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: Program returns the amount of numbers in an array which
 * are in allowed deviation from a given target, ignoring the number
 * itself in the array
 */

#include <stdio.h>

int main(int argc, char **argv){
	//input the array with the respect to the characters between the numbers
	int size;
	scanf("%i:", &size);
	int array[size];
	int i = 0;
	for(; i < size - 1; i++){
		scanf("%i,", &array[i]);
	}
	scanf("%i", &array[i]);
	
	//input the target value and allowed deviation
	int target, deviation;
	scanf("%i %i", &target, &deviation);
	
	//counting numbers within a range
	//we will count the given number itself, so we account for that by starting the counter at -1
	int counter = -1; 
	for(int i = 0; i < size; i++){
		//if the number is within the range we increase the counter
		if((target >= array[i] && target - deviation <= array[i])
		|| (target <= array[i] && target + deviation >= array[i])){
			counter++;
		}
	}
	
	//print the counter
	printf("%i\n", counter);
	
	return 0;
}

