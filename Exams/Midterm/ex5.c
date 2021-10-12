#include <stdio.h>

void printArray(int size, int array[size]){
	for(int i = 0; i < size; i++){
		printf("%i", array[i]);
		if(i != size - 1){
			printf(" ");
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int len1, len2;
	scanf("%i: ", &len1);
	int arr1[len1];
	
	for(int i = 0; i < len1; i++){
		scanf("%i", &arr1[i]);
	}
	
	scanf("%i: ", &len2);
	int arr2[len2];
	
	for(int i = 0; i < len2; i++){
		scanf("%i", &arr2[i]);
	}
	
	int counter = 0;
	
	if(len1<len2){
		for(int i = 0; i < len1; i++){
			int p = arr1[i];
			if(p<len2 && arr2[p]<len1 && arr2[p] == i){
				counter++;
			}
		}
	}
	
	if(len1>=len2){
		for(int i = 0; i < len2; i++){
			int p = arr2[i];
			if(p<len1 && arr1[p]<len2 && arr1[p] == i){
				counter++;
			}
		}
	}
	
	//printArray(len1, arr1);
	//printArray(len2, arr2);
	
	printf("%i\n", counter);
}
