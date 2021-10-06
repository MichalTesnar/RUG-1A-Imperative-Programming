#include <stdio.h>

void gridUpdate(int size, int arrayOne[size], int arrayTwo[size]){
	for(int i = 0; i < size; i++){
		arrayOne[i] = arrayTwo[i];
	}
}

int main(int argc, char **argv){
	int oldArray[10]={1};
	int newArray[10];
	
	for(int j = 0; j < 5; j++){
		newArray[0] = 1;
		printf("%i ", newArray[0]);
		for(int i = 1; i < 10; i++){
			newArray[i] = oldArray[i] + oldArray[i-1]; 
			printf("%i ", newArray[i]);
		}
		gridUpdate(10, oldArray, newArray);
		printf("\n");
	}
	

	return 0;
}
