/* Name:  Michal Tesnar, S4740556
 * Table: 00099911
 */

#include <stdio.h>

int reverse(int x){
	int reversed = 0;
	while(x!=0){
		reversed = reversed*10+x%10;
		x/=10;
	}
	return reversed;
}

int appendYtoX(int x, int y){
	while(y!=0){
		x = x*10+y%10;
		y/=10;
	}
	return x;

}


int main(int argc, char *argv[]) {
  
  int input;
  
  scanf("%i", &input);
  
  printf("%i\n", appendYtoX(input, input));
  
  
  return 0;
}
