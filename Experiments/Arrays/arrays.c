/*
 * arrays.c
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
#include <stdlib.h>
#include <time.h>

int printArray(int theArray[], int size){
	int i;
	printf("{");
	for(i=0; i<size-1; i++){
		printf("%d,", theArray[i]);
	}
	printf("%d}\n",theArray[size]);
	return 0;
}

int fillArrayRand(int anotherArray[], int size){
	int i;
	for(i=0; i<size; i++){
		anotherArray[i]=rand()%9+1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	
	int sizeOfArr = 10;
	
	int myArray[sizeOfArr];

	fillArrayRand(myArray, sizeOfArr);
	printArray(myArray, sizeOfArr);
	
	return 0;
}

