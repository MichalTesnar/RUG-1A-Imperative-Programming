#include <stdio.h>

int isPalindrom(int finish, char text[]){
	int i = 0;
	int j = finish-1;
	while(i != j && i < j){
		if(text[i]!=text[j]){
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

void recursive(char array[], int size, int index, int currentLength, char checked[], int *maximum){
	if(index == size){
		if(isPalindrom(currentLength, checked) && currentLength > *maximum){
			 *maximum = currentLength;
		}
		return;
	}
	checked[currentLength] = array[index];
	recursive(array, size, index + 1, currentLength + 1, checked, maximum);
	recursive(array, size, index + 1, currentLength, checked, maximum);
	return;
}

int main(int argc, char **argv)
{
	int size = 0;
	scanf("%i", &size);
	char text[size+1];
	char checked[size+1];
	scanf("%s", text);
	int maximum = 0;
	//printf("%i %s\n", size, text);
	//printf("%i\n", isPalindrom(size, text));
	recursive(text, size, 0, 0, checked, &maximum);
	printf("%i\n", maximum);
}
