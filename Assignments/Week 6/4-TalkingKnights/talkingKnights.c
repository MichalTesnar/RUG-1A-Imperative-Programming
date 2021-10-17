/*
 * file: talkingKnights.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: Given the board, starting position and the word we want
 * to get, program return whether (happy/unhappy) we can spell out given
 * word on the board just by doing knight moves.
 */

#include <stdio.h>

//returns boolean answer for whether move is possible on the board
int validMove(int rows, int columns, char array[rows][columns], int x, int y){
	if(x >= 0 && x < rows && y >= 0 && y < columns){
		return 1;
	}
	return 0;
}

//recursive function for jumping with the knight
int searchTheWord(int rows, int columns, char array[rows][columns],
	int x, int y, int wordLenght, int letterNumber, char word[]){
	//base case i.e. having found the end of the word
	if(letterNumber == wordLenght){
		return 1;
	}
	//if we are on the correct letter, search for all other possible knight moves
	if(array[x][y] == word[letterNumber]){
		for(int i = -2; i < 3; i++){
			for(int j = -2; j < 3; j++){
				//check if move is valid
				if(i!=j && j!= 0 && i!= 0 && validMove(rows, columns, array, x + i, y + j)){
					//check if given move return 1, if so then also return 1
					if(searchTheWord(rows, columns, array, x + i, y + j, wordLenght, letterNumber + 1, word)){
						return 1;
					}
				}	 
			}
		}
		//check for reuse of the same letter
		if(searchTheWord(rows, columns, array, x, y, wordLenght, letterNumber + 1, word)){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char **argv){
	//input the size of the array
	int columns, rows;
	scanf("%i %i\n", &columns, &rows);
	char array[rows][columns];
	
	//input the starting position
	int startX, startY;
	scanf("%i %i\n", &startX, &startY);
	
	//input the array itself
	for(int i = 0; i < rows; i++){
			scanf("%s", array[i]);
	}
	
	//input the word we look for
	int wordLength;
	scanf("%i", &wordLength);
	char word[wordLength];
	scanf("%s", word);

	//recursive function call
	int answer = searchTheWord(rows, columns, array, startY, startX, wordLength, 0, word);
	
	//print the result according to the binary value of the function
	if(answer == 1){
		printf("Happy\n");
	} else {
		printf("Unhappy\n");
	}
	return 0;
}

