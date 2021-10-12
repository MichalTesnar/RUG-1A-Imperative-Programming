/* Name:  Michal Tesnar, S4740556
 * Table: 00099911
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* place here your code */
  int n, digits=0;
  
  scanf("%i", &n);
  
  int manipulated = n;
  int reverse = 0;
  
  while(manipulated!=0){
	digits++;
	reverse = 10*reverse + manipulated%10;
	manipulated/=10;
  }
  
  printf("%i=",n);
  
  for(int i = digits; i > 0; i--){
	if(reverse%10 != 0){
		printf("%i*10^%i", reverse%10, i-1);
		
		
		
	}
	int x = (reverse/10)%10;
	if(x!=0){
			printf(" + ");
		}
	
	reverse/=10;
  }
  
  
  printf("\n");
  
  return 0;
}
