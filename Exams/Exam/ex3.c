#include <stdio.h>

void printArray(int array[], int size){
	for(int i = 0; i< size;i++){
		if(array[i] != 0){
			char letter = (char)(i+97);;
			printf("%c:%i\n", letter, array[i]);
		}
	}
}

int main(int argc, char **argv){
	char input;
	scanf("%c", &input);
	
	int array[30] = {0};

	char previous = '0';
	int counter = 1;
	
	while(input != '\n'){
		//printf("%c %c %i\n", previous, input, counter);
		if(input == previous){
			counter++;
		} else {
			int index = (int)previous;
			if(array[index-97]<counter){
				array[index-97] = counter;
			}
			
			counter = 1;
		}
		//int index = (int)input;
		//printf("%c %i\n", input, index);
		//array[index-97] = 2;
		//printf("%c", input);
		previous = input;
		scanf("%c", &input);
		
	
	}
	
	if(input == previous){
			counter++;
		} else {
			int index = (int)previous;
			if(array[index-97]<counter){
				array[index-97] = counter;
			}
			
			counter = 1;
		}
	
	printArray(array, 30);
}
