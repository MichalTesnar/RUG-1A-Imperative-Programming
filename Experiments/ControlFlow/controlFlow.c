/*
 * controlFlow.c
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
	int x = 1, y = 2, z = 3;
	
	if(y > x || y > z){
		printf("y is bigger then one of them\n");
	}
	
	if(z > x || z > y){
		printf("z is bigger then both of them\n");
	}
	
	char grade;
	
	printf("Give me your grade!\n");
	
	scanf("%c", &grade);
	
	switch(grade){
		case 'A':
			printf("Well done.");
			break;
		case 'B':
			printf("Not bad.");
			break;
		case 'C':
			printf("Better luck next time.");
			break;
		default:
			printf("You did not enter a valid grade.");		
		}
	
	
	return 0;
}

