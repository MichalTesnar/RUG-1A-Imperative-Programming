/*
 * file: removingValues.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: ***add here***
 */


#include <stdio.h>

//prints the array for control
void printArray(int array[], int size){	
	for(int i = 0; i < size; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
}

int main(int argc, char **argv){
	
	int removals, size;
	scanf("%i %i", &removals, &size);
	int array[size];
	
	for(int i = 0; i < size; i++){
		scanf("%i", &array[i]);
	}
	
	printArray(array, size);
	
	//printf("Hello world!\n");
	return 0;
}

