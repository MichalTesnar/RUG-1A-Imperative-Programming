#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	
	//we have boolean function which check whether something is a palindrom
	
	//we have minimum function to tell us which of two numbers is smaller
	
	//we check the function recursively
		//base case: the whole thing is a palindrom
		//we set the minimum we can return to the amount of numbers we have in the string we have sent
		//we iterate k over the rest of the string
			//if first part of the string (start to k) is a palindrom
				//we set minimum to what is smaller -> our previous minimum or 1 + minimum of the rest of the string
	//at the end we return the minimum
	
	//we print it to the screen
	

	return 0;
}
