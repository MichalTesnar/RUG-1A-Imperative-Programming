/*
 * guessGame.c
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
#include <time.h>
#include <stdlib.h>

/*
Game where you need to guess a number which was chosen at random beforehand
*/

int main(int argc, char **argv)
{
	srand(time(NULL));
	
	int victory = 1; //game loop controling variable
	
	int targetNumber; //the number user has to guess
	targetNumber = rand()%5+1;
	//printf("%i\n", targetNumber);
	
	int guessedNumber = 10;
	
	printf("I have chosen a number between 1 and 5. Try to guess it!\n");
	
	while(victory){
		
		scanf("%d", &guessedNumber);
		
		if(guessedNumber == targetNumber){
			printf("Congratulations! You won!");
			
			victory = 0;
			}
		else{
			printf("That is not it, try again!\n");
			}
		}
	return 0;
}

