#include <stdio.h>

int main(int argc, char **argv){
	
	int x = 7;
	
	*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&x/=2;
	
	printf("\a%i", x);
	return 0;
}

