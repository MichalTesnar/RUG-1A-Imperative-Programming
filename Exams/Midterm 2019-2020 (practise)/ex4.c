/* Name:  Michal Tesnar, S4740556
 * Table: 00099911
 */

#include <stdio.h>
#include <stdlib.h>

int power(int base, int exponent){
	int number=1;
	for(int i=0; i<exponent; i++){
		number*=base;
	}
	return number;
}

int main(int argc, char *argv[]) {
	int input;
	scanf("%i", &input);
	int counter = 0;
	int lookingAt = 1;
	
	while(counter!=input){
		
		int manipulated = lookingAt;
		int digits = 0;
  
		while(manipulated!=0){
			digits++;
			manipulated/=10;
		}
		
		manipulated = lookingAt;
		int sum = 0;
		for(int j = 0; j < digits; j++){
			sum+= power(manipulated%10, digits);
			manipulated/=10;
			
		}
		if(sum == lookingAt){
			//printf("%i %i %i\n", digits, lookingAt, sum); 
			counter++;
		}
		lookingAt++;
	}
	
	printf("%i\n", lookingAt-1);
	
	return 0;
}
