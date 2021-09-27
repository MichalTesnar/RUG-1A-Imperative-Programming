/*
 * file: functionEvaluator.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)>
 * 
 * Description: This program defines three functions
 * and executes them on a number in the order given
 * by input.
 */


#include <stdio.h>


void functionF(int *x){
	*x = 3*(*x)+1;
}

void functionG(int *x){
	*x = *x/2;
}

void functionH(int *x){
	*x = (*x)*(*x)-(*x);
}

int main(int argc, char **argv)
{
	int n; //input variable
	char functionOrder[10]; //commands to execute on the variable
	scanf("%i %s", &n, functionOrder);
	
	int i=0;
	while(functionOrder[i]!= '='){
		switch(functionOrder[i]){
			case 'f':
				functionF(&n);
				break;
			case 'g':
				functionG(&n);
				break;
			case 'h':
				functionH(&n);
				break;
		}
		i++;
	}
	printf("%i\n", n);
	return 0;
}

