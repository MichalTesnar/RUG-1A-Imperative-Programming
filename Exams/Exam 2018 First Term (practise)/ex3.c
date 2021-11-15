#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>


int binarySearch(int size, int target, int array[]){
	int left = 0;
	int right = size;
	while(left + 1 != right){
		int middle = (left + right)/2;
		if(target >= array[middle]){
			left = middle;
		} else {
			right = middle;
		}
	}
	return left;
}

void showArray(int length, int arr[]) {
  printf("%d", arr[0]);
  for (int i=1; i < length; i++) {
    printf(",%d", arr[i]);
  }
  printf("\n");
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

int main(int argc, char *argv[]) {
	int target;
	scanf("%i", &target);
	
	int isNone = 1;
	
	int array[1000001];
	
	int input;
	int length = 0;
	
	scanf("%i", &input);
	
	while(input!=0){
		array[length] = input;
		length++;
		scanf("%i", &input);
	}
	
	//printf("Before sorting:\n");
	//showArray(length, array);
	mergeSort(length, array);
	//printf("After sorting:\n");
	//showArray(length, array);
	
	
	for(int i = 0; i < length; i++){
		while(array[i] == array[i+1]){
			i++;
		}
		if(array[i] >= target - array[i]){
			break;
		}
		int search = binarySearch(length, target - array[i], array);
		if(array[search] == target- array[i]){
			printf("%i+%i\n", array[i], target- array[i]);
			isNone = 0;
		}
	
		
	}
	if(isNone){
		printf("NONE\n");
	} 
	
	return 0;
}
