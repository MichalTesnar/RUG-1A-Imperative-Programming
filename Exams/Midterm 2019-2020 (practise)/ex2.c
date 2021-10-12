/* Name:  Michal Tesnar, S4740556
 * Table: 00099911
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int input;
	int sumOfOddDigits = 0, sumOfEvenDigits = 0;
	
	scanf("%i", &input);
	
	while(input!=0){
		int lastDigit = input%10;
		if(lastDigit%2 == 0){
			sumOfEvenDigits+=lastDigit;
		} else {
			sumOfOddDigits+=lastDigit;
		}
		input/=10;
	}
	
	if(sumOfEvenDigits == sumOfOddDigits){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}
