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


int functionF(int x){
	return 3*x+1;
}

int functionG(int x){
	return x/2;
}

int functionH(int x){
	return x*x-x;
}

int main(int argc, char **argv)
{
	int n; //input variable
	char functionOrder[100000]; //commands to execute on the variable
	scanf("%i %s", &n, functionOrder);
	
	int i=0;
	while(functionOrder[i]!= '='){
		switch(functionOrder[i]){
			case 'f':
				n=functionF(n);
				break;
			case 'g':
				n=functionG(n);
				break;
			case 'h':
				n=functionH(n);
				break;
		}
		i++;
	}
	printf("%i\n", n);
	return 0;
}

