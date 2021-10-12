/*
 * file: rotationRings.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: For input n and and then n x n matrix and a defined
 * rotation (x coordinate, y coordinate, size of square, clockwise or
 * anti-clockwise) program changes the given matrix, end of input is
 * terminated by -1.
 */

#include <stdio.h>

//prints 2D array onto the screen
void print2DArray(int n, int array[n][n]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%i", array[i][j]);
			if(j != n - 1){
				printf(" ");
			}
		}
		printf("\n");
	}
}

//copies values from arrayTwo to arrayOne
void gridUpdate(int size, int arrayOne[size][size], int arrayTwo[size][size]){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			arrayOne[i][j] = arrayTwo[i][j];
		}
	}
}

//shifts numbers clockwise given the parameters, former array and new array to store values
void rightShift(int y, int x, int size, int n, int array[n][n], int newArray[n][n]){
	int parameter = size - 1;
	for(int i = y + parameter; i > y; i--){
		newArray[x][i] = array[x][i - 1];
	}
	for(int i = y; i < y + parameter; i++){
		newArray[x + parameter][i] = array[x + parameter][i + 1];
	}
	for(int i = x; i < x + parameter; i++){
		newArray[i][y] = array[i + 1][y];
	}
	for(int i = x + parameter; i > x; i--){
		newArray[i][y + parameter] = array[i - 1][y + parameter];
	}
}

//shifts numbers anti-clockwise given the parameters, former array and new array to store values
void leftShift(int y, int x, int size, int n, int array[n][n], int newArray[n][n]){
	int parameter = size - 1;
	for(int i = y + parameter; i > y; i--){
		newArray[x + parameter][i] = array[x + parameter][i - 1];
	}
	for(int i = y; i < y + parameter; i++){
		newArray[x][i] = array[x][i + 1];
	}
	for(int i = x; i < x + parameter; i++){
		newArray[i][y + parameter] = array[i + 1][y + parameter];
	}
	for(int i = x + parameter; i > x; i--){
		newArray[i][y] = array[i - 1][y];
	}
}

int main(int argc, char **argv){
	int n; //input size of the matrix
	scanf("%i", &n);
	
	int grid[n][n], newGrid[n][n]; //initialize grids
	
	//fill the grid and copy the values to the other one
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%i ", &grid[i][j]);
		}
	}	
	gridUpdate(n, newGrid, grid);
	
	//variables for manipulation input
	int x, y, size;
	char operand;
	
	//input first value to check whether we want to execute commands
	scanf("%i", &x);
	
	while(x != -1){
		scanf("%i %i %c", &y, &size, &operand); //input rest of commands
		
		//decide which rotation to make
		switch(operand){
				case '+':
					rightShift(x, y, size, n, grid, newGrid);
					break;
				case '-':
					leftShift(x, y, size, n, grid, newGrid);
					break;
				
			}
		gridUpdate(n, grid, newGrid);
		scanf("%i", &x);
	}
	print2DArray(n, grid);
	return 0;
}
