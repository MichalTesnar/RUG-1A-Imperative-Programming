/*
 * file: constrainedBistrings.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: Program outputs all possible bitstrings, which can be
 * created by filling empty spaces in the bistring by 0 or 1 so that
 * there are not more then two same characters next to each other.
 */

#include <stdio.h>

//check whether it is possible to enter a digit at a specified position
int digitPossible(char array[], int size, int position, char digit){
	if(position != 0 && array[position - 2] == digit && array[position - 1] == digit){
		return 0;
	}
	if(position != size - 1 && position != 0 && array[position - 1]==digit && array[position + 1] == digit){
		return 0;
	}
	if(position != size - 1 && array[position + 1] == digit && array[position + 2] == digit){
		return 0;
	}
	return 1;
}

//prints the array
void printArray(char array[], int size){	
	for(int i = 0; i < size; i++){
		printf("%c", array[i]);
	}
	printf("\n");
}

//recursive function for print all possible combinations for given bitstring
void possibleFills(char array[], int size, int index, int lastIndexChanged){
	//base case for being at the end of the array
	if(index == size){
		printArray(array, size);
		return;
	}
	//fill an unfilled digit
	if(array[index] == '?'){
		//fill 0 if possible
		if(digitPossible(array, size, index, '0') == 1){
			array[index] = '0';
			lastIndexChanged = index;
			possibleFills(array, size, index + 1, lastIndexChanged);
		}
		//fill 1 if possible
		if(digitPossible(array, size, index, '1') == 1){
			array[index] = '1';
			lastIndexChanged = index;
			possibleFills(array, size, index + 1, lastIndexChanged);
		}
		//refill the last filled digit before backtracking
		array[lastIndexChanged] = '?';
		return;
	}
	//pass an already filled digit
	possibleFills(array, size, index + 1, lastIndexChanged);
}

int main(int argc, char **argv){
	//input the size of the array
	int size;
	scanf("%i\n", &size);
	//input the array itself
	char array[size];
	for(int i = 0; i < size; i++){
		scanf("%c", &array[i]);
	}
	
	//recursive function call to print all the possible combinations
	possibleFills(array, size, 0, 0);
}
