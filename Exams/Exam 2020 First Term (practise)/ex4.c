#include <stdio.h>
#include <stdlib.h>


void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%i ", arr[i]);
	}
	printf("\n");
}

int abs(int x){
	return (x > 0 ? x : -x);
}

int *copySubArray(int left, int right, int arr[]) {
  int i, *copy = malloc((right - left)*sizeof(int));
  for (i=left; i < right; i++) {
    copy[i - left] = arr[i];
  }
  return copy;
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

int main(int argc, char *argv[]){
	
	int input1;
	scanf("%i:", &input1);
	int array1[input1];
	for(int i = 0; i < input1; i++){
		scanf("%i", &array1[i]);
	}
	
	int input2;
	scanf("%i:", &input2);
	int array2[input2];
	for(int i = 0; i < input2; i++){
		scanf("%i", &array2[i]);
	}
	//printArr(array1, input1);
	//printArr(array2, input2);
	mergeSort(input1, array1);
	mergeSort(input2, array2);
	//printArr(array1, input1);
	//printArr(array2, input2);
	
	int index1 = 0, index2 = 0;
	int skips = 0;
	
	while(index1!=input1 && index2 != input2){
		//printf("%i %i\n", array1[index1], array2[index2]);
		if(array1[index1] == array2[index2]){
			index1++;
			index2++;
			continue;
		}
		if(array1[index1] > array2[index2]){
			skips++;
			index2++;
		} else {
			skips++;
			index1++;
		}
	}
	/*
	printf("SKIPS %i\n", skips);
	printf("ONE %i\n", input1-index1);
	printf("TWO %i\n", input2-index2);
	*/
	printf("%i\n", skips + input1-index1 + input2-index2);
	return 0;
}
