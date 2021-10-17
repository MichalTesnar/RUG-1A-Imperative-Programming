/*
 * file: oneDGameOfLife.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: Cellular automaton in one dimension. Input is range
 * of the array, number of evolution steps and initial population.
 * Output is the final state of the population.
 */

#include <stdio.h>

//prints the values in an array
void printArray(int size, int array[size]){
	for(int i = 0; i < size; i++){
		printf("%i", array[i]);
		if(i != size - 1){
			printf(" ");
		}
	}
	printf("\n");
}

//counts number of alive neighbor cells of a given cell 
int aliveNeighbors(int size, int array[size], int position){
	int counter = 0;
	//position two to the right
	if((position + 2 >= size && array[position + 2 - size] == 1)
		|| (position + 2 < size && array[position + 2] == 1)){
		counter++;
	}
	//position one to the right
	if((position + 1 >= size && array[position + 1 - size] == 1)
		|| (position + 1 < size && array[position + 1] == 1)){
		counter++;
	}
	//position two to the left
	if((position - 2 < 0 && array[position - 2 + size] == 1)
		|| (position - 2 >= 0 && array[position - 2] == 1)){
		counter++;
	}
	//position one to the left
	if((position - 1 < 0 && array[position - 1 + size] == 1)
		|| (position - 1 >= 0 && array[position - 1] == 1)){
		counter++;
	}
	return counter;
}

//copies values from arrayTwo to arrayOne
void gridUpdate(int size, int arrayOne[size], int arrayTwo[size]){
	for(int i = 0; i < size; i++){
		arrayOne[i] = arrayTwo[i];
	}
}

int main(int argc, char **argv){
	
	int m, n; //size of the grid, simulation steps
	scanf("%i %i", &m, &n);
	int grid[m], newGrid[m]; //initialize grid and and another one to store new values
	
	//input grid and copy it to the other one
	for(int i = 0; i < m; i++){
		scanf("%i", &grid[i]);
	}
	gridUpdate(m, newGrid, grid);
	
	//evolution cycle
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			
			//count the number of alive neighbor cells
			int aliveNeighborsCount = aliveNeighbors(m, grid, j);
			
			//transition rules
			if(grid[j] == 0 && (aliveNeighborsCount == 2 || aliveNeighborsCount == 3)){
				newGrid[j] = 1; 
			}
			
			if(grid[j] == 1 && (aliveNeighborsCount != 2 && aliveNeighborsCount != 4)){
				newGrid[j] = 0;
			}		
		}
		//refresh grid
		gridUpdate(m, grid, newGrid);
	}
	printArray(m, grid);
	
	return 0;
}
