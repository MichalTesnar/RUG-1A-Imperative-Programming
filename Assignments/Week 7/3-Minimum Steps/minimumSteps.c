/*
 * file: minimumSteps.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: Returns the minimal amount of steps which are needed to
 * get from the first input number to the second one by applying one of
 * the three operations: increase by one, multiplying by two or
 * multiplying by three.
 */

#include <stdio.h>

#define INT_MAX 2147483647

//recursive function to calculate the minimum amount of steps needed
void steps(int start, int target, int counter, int *minimum){
	//base case: if we have found the target, we can update the minimum and return
	if(start == target){
		if(counter < *minimum){
			*minimum = counter;
		}
		return;
	}
	//base case: if we have passed the target already or our counter is bigger the minimum we have found
	if(start > target || counter > *minimum){
		return;
	}
	
	//if our target is divisible by three, by divide it and call again with increased counter
	if(target%3 == 0){		
		steps(start, target/3, counter + 1, minimum);
	}
	//if our target is divisible by two, by divide it and call again
	if(target%2 == 0){		
		steps(start, target/2, counter + 1, minimum);
	}
	//we can always decrease the target by one
	steps(start, target - 1, counter + 1, minimum);
}

int main(int argc, char **argv){
	//input of starting and target number
	int start, target;
	scanf("%i %i", &start, &target);
	
	//variable to save the minimum amount of steps we have need to achieve the target so far 
	int minimum = INT_MAX;
	
	//recursive function call, minimum is passed as an address
	steps(start, target, 0, &minimum);
	
	//print the minimum we have achieved
	printf("%i\n", minimum);
	
	return 0;
}
