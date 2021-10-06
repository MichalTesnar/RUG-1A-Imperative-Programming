/*
 * file: ***nameOfTheProgram***.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: ***add here***
 */


#include <stdio.h>

void print2DArray(int n, int array[n][n]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%i", array[i][j]);
		if(j!=n-1){
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

void rightShift(int y, int x, int size, int n, int array[n][n], int newArray[n][n]){
	int parameter = size - 1;
	for(int i = y+parameter; i > y; i--){
		newArray[x][i] = array[x][i-1];
	}
	for(int i = y; i < y + parameter; i++){
		newArray[x+parameter][i] = array[x+parameter][i+1];
	}
	for(int i = x; i < x + parameter; i++){
		newArray[i][y] = array[i+1][y];
	}
	for(int i = x + parameter; i > x; i--){
		newArray[i][y+parameter] = array[i-1][y+parameter];
	}
}

void leftShift(int y, int x, int size, int n, int array[n][n], int newArray[n][n]){
	int parameter = size - 1;
	
	for(int i = y+parameter; i > y; i--){
		newArray[x+parameter][i] = array[x+parameter][i-1];
	}
	for(int i = y; i < y + parameter; i++){
		newArray[x][i] = array[x][i+1];
	}
	for(int i = x; i < x + parameter; i++){
		newArray[i][y+parameter] = array[i+1][y+parameter];
	}
	for(int i = x + parameter; i > x; i--){
		newArray[i][y] = array[i-1][y];
	}
	
}

int main(int argc, char **argv){
	
	/*
	int n = 5; //grid size
	int grid[5][5]={{1, 2, 3, 4, 5},
					{16, 17, 18, 19, 6},
					{15, 24, 25, 20, 7},
					{14, 23, 22, 21, 8},
					{13, 12, 11, 10, 9}};

	int newGrid[5][5]={0};
	*/
	int n;
	scanf("%i", &n);
	int grid[n][n], newGrid[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%i ", &grid[i][j]);
		}
	}	
	
	//print2DArray(n, grid);
	gridUpdate(n, newGrid, grid);
	char operand;
	int x, y, size;
	
	while(1){
		scanf("%i", &x);
		if(x == -1){
			print2DArray(n, grid);
			return 0;
		}
		scanf("%i %i %c", &y, &size, &operand);
		//printf("%i %i %i %c", x, y, size, operand);

		switch(operand){
				case '+':
					//printf("PLUS\n");
					rightShift(x, y, size, n, grid, newGrid);
					break;
				case '-':
					//printf("MINUS\n");
					leftShift(x, y, size, n, grid, newGrid);
					//do counterclockwise rotation with the commands
					break;
				
			}
		gridUpdate(n, grid, newGrid);
		
	}
	//print2DArray(n, grid);

	
	return 0;
}

