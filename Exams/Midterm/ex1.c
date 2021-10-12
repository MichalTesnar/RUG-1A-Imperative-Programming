#include <stdio.h>

int main(int argc, char **argv)
{
	int a1, a2, b1, b2;
	char operator;
	
	scanf("%i/%i%c%i/%i", &a1, &a2, &operator, &b1, &b2);
	int value1 = a1*b2;
	int value2 = a2*b1;
	
	if((operator == '<' && value1<value2) || (operator == '>' && value1>value2)){
		printf("YES\n");
		
	} else {
		printf("NO\n");
	}
	
	//printf("%i %i\n", value1, value2);
	
	
}
