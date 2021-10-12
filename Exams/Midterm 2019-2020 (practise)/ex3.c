/* Name:  Michal Tesnar, S4740556
 * Table: 00099911
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//55 minutes
  
  int budget, roll;
  int bet = 1;
  int outcome = 1;
  scanf("%i", &budget);
  scanf("%i", &roll);
 
  
  while(roll != -1){
	switch(roll){
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		case 12:
		case 14:
		case 16:
		case 18:
		case 19:
		case 21:
		case 23:
		case 25:
		case 27:
		case 30:
		case 32:
		case 34:
		case 36:
			outcome = 1;
			break;
		default:
			outcome = 0;
			break;
	}
		
	if(outcome == 1){
		budget+=bet;
		bet = 1;
	} else if(bet*2>budget){
		printf("BUST\n");
		return 0;
	} else {
		budget-=bet;
		bet*=2;
	}
	
	scanf("%i", &roll);
	}

  printf("%i\n", budget);
  return 0;
}
