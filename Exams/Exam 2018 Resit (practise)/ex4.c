#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	//we do not need to allocate memory for the numbers, since we process them as they go until we find a zero
	
	//we need the current sum of numbers to be greater than zero and we keep track of the global maximum
	
	//we start with sum 0
	//we look at the next number and ask whether adding it makes our sum greater than zero
		//->YES: add it to the sum and go to the next index
			//if we are over the maximum, update the maximum
		//->NO: set current sum to 0 and go to the next index
		
	//print the maximum we have found
	
	return 0;
}
