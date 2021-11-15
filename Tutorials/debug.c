#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int N = 100000;
	int k = 2;
	int s = 1;
	while (s < N) {
		s = 2*s;
		
		for (int i = s; i > 0; i--) {
			k++;
		}
		printf("%i %i\n", s, k);
	}
	printf("%i\n", k);
	
	return 0;
}
