/* Name:  Michal Tesnar, S4740556
 * Table: 00099911
 */

#include <stdio.h>

int power(int base, int exponent){
	int result = 1;
	while(exponent!=0){
		result*=base;
		exponent--;
	}

	return result;
}

int reverse(int x){
	int reversed = 0;
	while(x!=0){
		reversed = reversed*10+x%10;
		x/=10;
	}
	return reversed;
}


int main(int argc, char *argv[]) {

	int input;
	scanf("%i", &input);
	int copy = reverse(input);
	
	int sum = 0;
	int counter = 1;
	
	while(copy!=0){
		sum+=power(copy%10, counter);
		copy/=10;
		counter++;
		}
	
	//printf("%i\n", sum);
	
	if(sum == input){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}
