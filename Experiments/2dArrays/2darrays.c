/*
 * 2darrays.c
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

#define ROWS 10
#define COLS 10

void fillArrayRand(int arr[ROWS][COLS]){
	srand(time(NULL));
	int i=1, j=1;
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLS;j++){
			arr[i][j]=rand()%10;
			}
		}
}

void fillArrayZeros(int arr[ROWS][COLS]){
	srand(time(NULL));
	int i=1, j=1;
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLS;j++){
			arr[i][j]=0;
			}
		}
}
	
void printArray(int arr[ROWS][COLS]){
	int i=1, j=1;
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLS;j++){
			//~ printf("i=%i, j=%i, element=%i\n", arr[i][j]);
			printf("%i",arr[i][j]);
			}
			printf("\n");
		}
}

int main(int argc, char **argv)
{
	int TwoDArr[ROWS][COLS];
	int iPosition = 5;
	int jPosition = 5;
	char move;
	
	int i=0;
	for(i=0;i<100;i++){
		fillArrayZeros(TwoDArr);
		TwoDArr[iPosition][jPosition]=1;
		printArray(TwoDArr);
		scanf("%c",&move);
		printf("%i, %i\n",iPosition, jPosition);
		
		switch(move){
			case 'a':
				jPosition-=1;
				printf("a\n");
				break;
			case 'd':
				jPosition+=1;
				printf("d\n");
				break;
			case 's':
				iPosition+=1;
				printf("s\n");
				break;
			case 'w':
				iPosition-=1;
				printf("w\n");
				break;
			default:
				printf("Invalid key.\n");
			}		
	}
	return 0;
}
