#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%i ", arr[i]);
	}
	printf("\n");
}

int recursive(int size, int array[], int currentSum, int index, int adds){
	//printf("i: %i sum: %i adds %i\n",index,  currentSum , adds);
	if(index == size){
		return currentSum;
	}
	if(adds == 0){
		return recursive(size, array, currentSum, index + 1, 2);
	}
	int value1 = recursive(size, array, currentSum, index + 1, 2);
	int value2 = recursive(size, array, currentSum + array[index], index + 1, adds - 1);
	return (value1 > value2 ? value1 : value2);
}


int main(int argc, char *argv[]){
	
	int size;
	scanf("%i:", &size);
	int array[size];
	for(int i = 0; i < size; i++){
		scanf("%i", &array[i]);
	}
	
	
	//printArr(array, size);
	
	printf("%i\n", recursive(size, array, 0, 0, 2));
	
	return 0;
}
