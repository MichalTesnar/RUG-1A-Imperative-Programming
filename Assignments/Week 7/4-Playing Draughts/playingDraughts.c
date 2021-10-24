/*
 * file: playingDraughts.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: On the 8x8 board, program returns the maximum possible
 * amount of pieces eaten in a game of draughts by jumping diagonally
 * over other pieces.
 */

#include <stdio.h>

#define BOARD_SIZE 8

//returns boolean answer for whether move is possible on the board
int validMove(char array[BOARD_SIZE][BOARD_SIZE], int x, int y){
	if(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && array[x][y] != 'W'){
		return 1;
	}
	return 0;
}

//returns boolean value for whether give spot on a board has a piece that can be jumped over
int hasPiece(char array[BOARD_SIZE][BOARD_SIZE], int x, int y){
	if(array[x][y] == 'W'){
		return 1;
	}
	return 0;
}

//fills array with zeros
void fillArray(int size, char array[BOARD_SIZE][BOARD_SIZE]){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			array[i][j] = '0';
		}
	}
}

//recursive function for eating the pieces
int jumpAndEat(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int counter){
	//each value corresponds to a move in one direction, we calculate it if it is possible to do so
	int value1 = -1, value2 = -1, value3 = -1, value4 = -1;
	if(hasPiece(board, x + 1, y + 1) && validMove(board, x + 2, y + 2)){
		//if we can make the move, we eat the piece before changing position
		board[x + 1][y + 1] = '0';
		value1 = jumpAndEat(board, x + 2, y + 2, counter + 1);
		//and after return from the call we reset the value
		board[x + 1][y + 1] = 'W';
	}
	if(hasPiece(board, x + 1, y - 1) && validMove(board, x + 2, y - 2)){
		board[x + 1][y - 1] = '0';
		value2 = jumpAndEat(board, x + 2, y - 2, counter + 1);
		board[x + 1][y - 1] = 'W';
	}
	if(hasPiece(board, x - 1, y + 1) && validMove(board, x - 2, y + 2)){
		board[x - 1][y + 1] = '0';
		value3 = jumpAndEat(board, x - 2, y + 2, counter + 1);
		board[x - 1][y + 1] = 'W';
	}
	if(hasPiece(board, x - 1, y - 1) && validMove(board, x - 2, y - 2)){
		board[x - 1][y - 1] = '0';
		value4 = jumpAndEat(board, x - 2, y - 2, counter + 1);
		board[x - 1][y - 1] = 'W';
	}
	
	//if none of the values could have been calculated, we came to an end
	if(value1 == -1 && value2 == -1 && value3 == -1 && value4 == -1){
		return counter;
	}
	//returning the biggest value of the four
	if(value1 >= value2 && value1 >= value3 && value1 >= value4){
		return value1;
	}
	if(value2 >= value1 && value2 >= value3 && value2 >= value4){
		return value2;
	}
	if(value3 >= value1 && value3 >= value2 && value3 >= value4){
		return value3;
	}
	if(value4 >= value1 && value4 >= value2 && value4 >= value3){
		return value4;
	}
}

int main(int argc, char **argv){
	//inputing the starting position and the number of white pieces
	int xPosition, yPosition, numberOfPieces;
	scanf("%i %i %i", &xPosition, &yPosition, &numberOfPieces);
	
	//declaring an array for the board, fill it with zeros
	char board[BOARD_SIZE][BOARD_SIZE] = {{0}};
	fillArray(BOARD_SIZE, board);
	
	//inputing all the pieces as 'W' into the array
	for(int i = 0; i < numberOfPieces; i++){
		int x, y;
		scanf("%i %i", &x, &y);
		board[x][y] = 'W';
	}
	
	//printing the return value of the recursive function
	printf("%i\n", jumpAndEat(board, xPosition, yPosition, 0));
	
	return 0;
}
