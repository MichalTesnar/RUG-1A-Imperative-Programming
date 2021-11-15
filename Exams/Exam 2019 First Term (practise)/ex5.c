#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size){
	for(int i = 0; i < size; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
}

int precompFib(int array[], int size, int max){
	array[0] = 1;
	array[1] = 2;
	int index = 2;
	while(index < size && array[index-1]<max){
		array[index] = array[index-1] + array[index-2];
		index++;
	}
	return index;
}

int recursive(int currentSum, int targetSum, int size, int index, int array[]){
	if(index == size){
		return (targetSum == currentSum);
	}
	return recursive(currentSum + array[index], targetSum, size, index + 1, array)
		+ recursive(currentSum, targetSum, size, index + 1, array);
}

int main(int argc, char *argv[]){
	
	int input;
	scanf("%i", &input);
	
	int array[input];
	int max = precompFib(array, input, input);
	//printArray(array, max);
	
	int i = recursive(0, input, max, 0, array);
	
	printf("%i\n", i);
	
	return 0;
}
