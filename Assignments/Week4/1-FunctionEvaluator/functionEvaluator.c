/*
 * file: functionEvaluator.c
 * 
 * author: Michal Tešnar (m.tesnar@studen.rug.nl)>
 * 
 * Description: This program defines three functions
 * and executes them on a number in the order given
 * by input.
 */


#include <stdio.h>

int functionF(int *x){
	return 3*(*x)+1;
}

int functionG(int *x){
	return *x/2;
}

int functionH(int *x){
	return (*x)*(*x)-(*x);
}

int main(int argc, char **argv)
{
	int n; //input variable
	char functionOrder[]; //commands to execute on the variable
	scanf("%i %s", &n, functionOrder);
	printf("%i %i %i", functionF(&n), functionG(&n), functionH(&n));
	return 0;
}

