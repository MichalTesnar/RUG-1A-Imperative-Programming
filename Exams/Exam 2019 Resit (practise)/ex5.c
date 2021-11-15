/*
 * file: ***nameOfTheProgram***.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: ***add here***
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
	int input;
	scanf("%i", &input);
	printf("%i\n", (int)(input*(input+1)/2*pow(2, input-1)));
	return 0;
}
