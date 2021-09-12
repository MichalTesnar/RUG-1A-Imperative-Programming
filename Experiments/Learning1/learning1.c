/*
 * learning1.c
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


int looping(int a){
	
	int i; //iterable variable
	
	for(i=1; i<5; i++){
		printf("How to enter characters: %i is a number, %i is another one\n", i, a);
		}
	return 0;
	}
	
int arrays(int c){
	
	int arr[5] = {7, 8, 9, 22, 78};
	
	int x = arr[0];
	
	int i;
	for(i = 1; i<6;i++){
		x = arr[i-1];
		printf("The %i. item is %i.\n", i, x);
		}
		
	return 0;
	}

int main(int argc, char **argv)
{	
	printf("Hello world!\n");
	
	//looping(7);
	
	arrays(3);	
	
	return 0;
}

