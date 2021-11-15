#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c){
	a = (a > b ? a : b);
	a = (a > c ? a : c);
	return a;
}


int main(int argc, char *argv[]) {
	int input;
	
	scanf("%i", &input);
	
	int array[input];
	
	for(int i = 0; i < input; i++){
		scanf("%i", &array[i]);
	}
	/*
	for(int i = 0; i < input; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
	*/
	for(int i = 0; i < input -1; i++){
		array[i+1] += array[i];
	}
	
	/*
	for(int i = 0; i < input; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
	*/
	
	int index1 = 0;
	int index2 = 0;
	
	int sum = array[input-1];
	
	int maxsum = 1000000;
	
	while(index1 != input-1){
		index2 = index1;
		while(index2 != input-2){
			index2++;
			//printf("%i %i\n", index1, index2);
			int value1 = array[index1];
			int value2 = array[index2]-value1;
			int value3 = sum - value2 - value1;
			int value = max(value1, value2, value3);
			//printf("%i %i %i\n", value1, value2, value3);
			if(value < maxsum){
				maxsum = value;
			}
			//printf("%i\n", maxsum);
		}
		index1++;
	}
	
	printf("%i\n", maxsum);
	
	return 0;
}
