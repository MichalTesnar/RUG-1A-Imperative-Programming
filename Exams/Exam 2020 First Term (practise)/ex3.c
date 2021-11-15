#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%i ", arr[i]);
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

int main(int argc, char *argv[]){
	
	int start, target;
	scanf("%i %i", &start, &target);
	
	int copy = start;
	int digits = 0;
	while(copy!=0){
		digits++;
		copy/=10;
	}
	int arr1[digits];
	for(int i = 0; i < digits; i++){
		arr1[i] = start%10;
		start/=10;
	}
	
	//printArr(arr1, digits);
	//mergeSort(digits, arr1);
	//printArr(arr1, digits);
	
	//!!! YOU COULD HAVE MADE A HISTOGRAM OF THE DIGITS AND USE THAT
	//FOR THE SECOND INPUT YOU WOULD JUST GO THROUGH ALL THE POSITIONS IN THE ARRAY UNTIL YOU FIND A NUMBER
		//IF YOU DO NOT COME TO THE END, YOU SAY NO
	
	while(target!=0){
		int looking = target%10;
		int found = 0;
		for(int i = 0; i < digits; i++){
			if(arr1[i] == looking){
				arr1[i] = -1;
				found = 1;
				break;
			}
		}
		if(found == 0){
			printf("NO\n");
			return 0;
		}
		target/=10;
	}
	int empty = 1;
	for(int i = 0; i < digits; i++){
		if(arr1[i] != -1){
			empty = 0;
		}
	}
	//printArr(arr1, digits);
	if(empty){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	
	
	return 0;
}
