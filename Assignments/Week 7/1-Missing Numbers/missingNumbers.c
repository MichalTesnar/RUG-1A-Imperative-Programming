/*
 * file: missingNumbers.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: Program dynamically inputs and array of any size
 * and then returns the number of numbers missing from the range
 * specified by the highest and the smallest number.
 */


#include <stdio.h>
#include <stdlib.h>


//swap function copied from the reader
void swap(int i, int j, int arr[]){
	int h = arr[i];
	arr[i] = arr[j];
	arr[j] = h;
}

//partition function copied from the reader
int partition (int length, int arr[]){
	int left = 0;
	int right = length;
	int pivot = arr[0];
	while (left < right){
		while ((left < right) && (arr[left] <= pivot)){
			left++;
		}
		while ((left < right) && (pivot < arr[right-1])){
			right--;
		}
		if (left < right){
			/* (arr[left] > pivot) && (arr[right-1] <= pivot) : swap */
			right--;
			swap(left, right, arr);
			left++;
		}
	}
	/* put pivot in right location: swap(0,left-1, arr) */
	left--;
	arr[0] = arr[left];
	arr[left] = pivot;
	return left;
}

//quickSort function copied from the reader
void quickSort(int length, int arr[]){
	int boundary;
	if (length <= 1) {
		return; /* empty or singleton array: nothing to sort */
	}
	boundary = partition(length, arr);
	quickSort(boundary, arr);
	quickSort(length - boundary - 1, &arr[boundary + 1]);
}

int main(int argc, char **argv){
	//creating a dynamic array
	int size = 1;
	int *pArray = malloc(size*sizeof(int));
	//input of the first number, insert it into the array
	int input;
	scanf("%i,", &input);
	pArray[0] = input; 
	
	//inputing all the other numbers
	while(scanf("%i,", &input)){
		if(input == -1){
			break;
		}
		//dynamically increasing the size of the array
		size += 1;
		pArray = realloc(pArray, (size)*sizeof(int));
		//inputing the last number at the last index
		pArray[size - 1] = input;
	}
	
	//sorting the array we have
	quickSort(size, pArray);
	
	//count the missing digits by measuring the between consecutive numbers
	int counter = 0;
	for(int i = 0; i < size - 1; i++){
		if(pArray[i + 1] != pArray[i]){
			counter += pArray[i + 1] - pArray[i] - 1;
		}
	}
	
	//printing the number of missing digits
	printf("%i\n", counter);
	
	//free the memory we malloc-ed
	free(pArray);
	
	return 0;
}
