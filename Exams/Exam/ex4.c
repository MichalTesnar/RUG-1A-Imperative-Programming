#include <stdio.h>

#define INT_MIN -32768


void printArray(int array[], int size){
	for(int i = 0; i< size;i++){
		printf("%i ", array[i]);
	}
	printf("\n");
}

int recursive(int array[], int size, int index, int mustSkip, int currentSum, int values){
	if(index == size){
		if(values > 1){
			return currentSum;
		} else {
			return INT_MIN;
		}
		
	}
	int skip = recursive(array, size, index + 1, 0, currentSum, values);
	int adding = recursive(array, size, index + 1, 1, currentSum + array[index], values + 1);
	if(mustSkip){
		adding = INT_MIN;
	}
	/* CORRECT SOLUTION, which is faster, since it prefers a faster case
	int adding;
	if(mustSkip == 1){
		adding = INT_MIN;
	} else {
		adding = recursive(array, size, index + 1, 1, currentSum + array[index], values + 1);
	}
	*/
	
	return (skip > adding ? skip : adding);
}

int main(int argc, char **argv)
{
   int input;
   scanf("%i", &input);
   int array[input];
   for(int i = 0; i < input; i++){
	   scanf("%i", &array[i]);
   }
   
   //printArray(array, input);
   
   printf("%i\n", recursive(array, input, 0, 0, 0, 0));
   
   
}
