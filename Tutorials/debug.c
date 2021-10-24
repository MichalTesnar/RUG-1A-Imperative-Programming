#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double factorial(double x){
	if(x == 1){
		return 1;
	}
	return x*factorial(x-1);
}

int main(int argc, char **argv){
	
	int i = 0;
	char string[25];
	
	scanf("%s", string);
	
	i = strlen(string);
	
	printf("%i\n", i);
	
	return 0;
}
