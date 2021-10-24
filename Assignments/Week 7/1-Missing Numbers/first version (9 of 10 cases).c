/*
 * file: missingNumbers.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: First version
 */


#include <stdio.h>
#include <stdlib.h>

void printArray(int size, int array[]){
	for(int i = 0; i < size; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
}

int binarySearch(int size, int target, int array[]){
	int left = 0;
	int right = size;
	while(left + 1 != right){
		int middle = (left + right)/2;
		if(target >= array[middle]){
			left = middle;
		} else {
			right = middle;
		}
	}
	return left;
}

int *resizeArray(int oldSize, int *array, int newNumber, int position){
	int *pointer = malloc((oldSize + 1)*sizeof(int));
	int i;
	for(i = 0; i < position; i++){
		pointer[i] = array[i];
	}
	pointer[i] = newNumber;
	i++;
	for(; i < oldSize + 1; i++){
		pointer[i] = array[i-1];
	}
	free(array);
	return pointer;	
}

int main(int argc, char **argv){

	int input;
	scanf("%i,", &input);
	int maximum = input, minimum = input;
	int size = 1;
	int *pArray = malloc((size)*sizeof(int));
	pArray[0] = input;

	while(scanf("%i,", &input)){
		if(input == -1){
			break;
		}
		
		if(input > maximum){
			maximum = input;
			pArray = resizeArray(size, pArray, input, size);
			size += 1;
		}
		else if (input < minimum){
			minimum = input;
			pArray = resizeArray(size, pArray, input, 0);
			size += 1;
			
		} else {
			int search = binarySearch(size, input, pArray);
			if(pArray[search] != input){
				pArray = resizeArray(size, pArray, input, search + 1);
				size += 1;
			}
		}
		//printArray(size, pArray);
	}
	
	
	//count the missing digits
	int counter = 0;
	for(int i = 0; i < size-1; i++){
		counter += pArray[i+1] - pArray[i] - 1;
	}
	printf("%i\n", counter);

	return 0;
}
