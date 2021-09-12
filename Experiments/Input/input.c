/*
 * input.c
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


int main(int argc, char **argv)
{
	/* inputing integers
	int x;
	printf("Give me a whole number: ");
	scanf("%d", &x);
	printf("Your number is %d.\n", x);
	*/
	
	/* inputing numbers with floating points
	double y;
	printf("Give me a number with a floating point: ");
	scanf("%lf", &y);
	printf("Your number is %f.\n", y);
	*/
	
	/* inputing characters
	char z;
	printf("Give me a character: ");
	scanf("%c", &z);
	printf("Your character is %c.\n", z);
	*/
	
	/*inputing strings using scanf
	char name[20];
	printf("Give me your name: ");
	scanf("%s", name);
	printf("Your name is %s.\n", name);
	*/
	
	//inputing strings with blank spaces, takes enter as a \n character
	/*
	char name[20];
	printf("Give me your name: ");
	fgets(name, 20, stdin);
	printf("Your name is %s. Beware of the \\n-problem \n", name);
	*/
	
	char firstName[60];
	char secondName[60];
	printf("Write two words please.\n");
	scanf("%s%s", firstName, secondName);
	printf("This is the first %s, and this is the second one: %s\n", firstName, secondName);
	
	return 0;
}

