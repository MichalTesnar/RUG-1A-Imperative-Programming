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

//creation of a dynamic array, copied from the reader
int *dynamicIntArray(int size){
	int *ptr = malloc(size*sizeof(int));
	return ptr;
}

//copying a subarray from an array, copied from the reader
int *copySubArray(int left, int right, int arr[]){
	int i;
	int *copy = dynamicIntArray((right-left)*sizeof(int));
	for(i = left; i < right; i++){
		copy[i - left] = arr[i];
	}
	return copy;
}

//mergeSort function copied from the reader
void mergeSort(int length, int arr[]) {
	int l, r, mid, idx, *left, *right;
	if(length <= 1){
		return;
	}
	mid = length/2;
	left = copySubArray(0, mid, arr);
	right = copySubArray(mid, length, arr);
	mergeSort(mid, left);
	mergeSort(length - mid, right);
	idx = 0;
	l = 0;
	r = 0;
	while((l < mid) && (r < length - mid)){
		if (left[l] < right[r]){
			arr[idx] = left[l];
			l++;
		}else{
			arr[idx] = right[r];
			r++;
		}
		idx++;
	}
	while(l < mid){
		arr[idx] = left[l];
		idx++;
		l++;
	}
	while(r < length - mid){
		arr[idx] = right[r];
		idx++;
		r++;
	}
	free(left);
	free(right);
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
	mergeSort(size, pArray);
	
	//count the missing digits by measuring the difference between consecutive numbers
	int counter = 0;
	for(int i = 0; i < size - 1; i++){
		if(pArray[i + 1] != pArray[i]){
			counter += pArray[i + 1] - pArray[i] - 1;
		}
	}
	
	//printing the number of missing digits
	printf("%i\n", counter);
	
	return 0;
}
