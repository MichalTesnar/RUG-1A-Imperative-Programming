#include <stdio.h>
#include <stdlib.h>

int binarySearch(int val, int len, int arr[]) {
	int left = 0, right = len;
	while (left < right) {
		int mid = (left + right)/2;
	if (arr[mid] < val) {
	left = mid + 1;
	} else {
	right = mid;
	}
	}
	return left;
}

int *copySubArray(int left, int right, int arr[]) {
  int i, *copy = malloc((right - left)*sizeof(int));
  for (i=left; i < right; i++) {
    copy[i - left] = arr[i];
  }
  return copy;
}

int howOften(int array[], int size, int value){
	int counter = 0;
	int search = binarySearch(value, size, array);
	while(array[search] == value){
		search++;
		counter++;
	}
	return counter;
}

void mergeSort(int length, int arr[]) {
  int l, r, mid, idx, *left, *right;
  if (length <= 1) {
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
  while ((l < mid) && (r < length - mid)) {
    if (left[l] < right[r]) {
      arr[idx] = left[l];
      l++;
    } else {
      arr[idx] = right[r];
      r++;
    }
    idx++;
  }
  while (l < mid) {
    arr[idx] = left[l];
    idx++;
    l++;
  }
  while (r < length - mid) {
    arr[idx] = right[r];
    idx++;
    r++;
  }
  free(left);
  free(right);
}

void printArr(int size, int array[]){
	for(int i = 0; i < size; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int amount, threshold;
	scanf("%i %i:", &amount, &threshold);
	
	int array[amount];
	int arrayCopy[amount];
	
	for(int i = 0; i < amount; i++){
		scanf("%i", &array[i]);
		arrayCopy[i] = array[i];
		
		getchar();
	}
	
	mergeSort(amount, arrayCopy);
	//printArr(amount, array);
	//printArr(amount, arrayCopy);
	int first = 1;

	for(int i = 0; i < amount; i++){
		int counter = howOften(arrayCopy, amount, array[i]);
		//printf("%i %i %i\n", i, array[i], counter);
		if(counter<threshold){
			if(first){
				printf("%i", array[i]);
				first = 0;
			} else {
				printf(",%i", array[i]);
			}
			
			
		}
		
	}
	
	printf("\n");
	//printArr(maximum, frequency);
	
	
	return 0;
}
