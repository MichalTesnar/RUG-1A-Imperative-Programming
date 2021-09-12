/*
 * calculator.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	//variables
	float x1, x2; //computational variables
	char SYM; //symbol of the operation
	
	//choosing operation
	printf("Enter the operation you want to do ('+', '-', '/', 'x'): ");
	scanf("%c", &SYM);
	
	//input prompts
	printf("Enter the first number: ");
	scanf("%f", &x1);
	
	printf("Enter the second number: ");
	scanf("%f", &x2);

	//printf("%f, %f, %c\n", x1, x2, SYM);
	
	switch(SYM)
	{
		case '+':
			printf("The sum is %f.",x1+x2);
			break;
		case '-':
			printf("The difference is %f.",x1-x2);
			break;
		case '/':
			printf("The quotient is %f.",x1/x2);
			break;
		case 'x':
			printf("The product is %f.",x1*x2);
			break;
		default:
			printf("Operator does not match the selection.");
	}
	
	return 0;
}

