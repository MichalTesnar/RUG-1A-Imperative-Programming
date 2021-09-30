/*
 * file: functionEvaluator.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: This program defines three functions
 * and executes them on a number in the order given
 * by input.
 */

#include <stdio.h>

int functionF(int x){
	return 3*x + 1;
}

int functionG(int x){
	return x/2;
}

int functionH(int x){
	return x*x - x;
}

int main(int argc, char **argv){
	int n; //input variable
	char command; //commands to execute on the variable
	scanf("%i", &n);
	
	//Go through the commands until the '=' and execute them on the variable.
	while(scanf("%c", &command)){
		switch(command){
			case 'f':
				n = functionF(n);
				break;
			case 'g':
				n = functionG(n);
				break;
			case 'h':
				n = functionH(n);
				break;
		}
		if(command == '='){
			break;
		}
	}
	
	printf("%i\n", n);
	return 0;
}

