#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	
	int x = 7;
	
	*&*&*&*&*&*&*&x/=2;
	exit(-1);
	printf("\a%i", x);
	return 0;
}

