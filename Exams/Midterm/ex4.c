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

//copies values from arrayTwo to arrayOne
void gridUpdate(int size, int arrayOne[size], int arrayTwo[size]){
	for(int i = 0; i < size; i++){
		arrayOne[i] = arrayTwo[i];
	}
}

int absolute(int x){
	if(x<=0){
		return -x;
	}
	return x;
}

void recalculateGrid(int size, int grid[], int newGrid[]){
	for(int i = 0; i < size-1; i++){
		//printf("%i %i %i\n", grid[i], grid[i+1], absolute(grid[i]-grid[i+1]) );
		newGrid[i]=absolute(grid[i]-grid[i+1]);
	}
}


int main(int argc, char **argv){
	
	int m;
	scanf("%i", &m);
	int grid[m], newGrid[m]; 
	
	for(int i = 0; i < m; i++){
		scanf("%i", &grid[i]);
	}
	//gridUpdate(m, newGrid, grid);
	printArray(m, grid);
	for(int i = m - 1; i > 0; i--){
		recalculateGrid(i+1, grid, newGrid);
		gridUpdate(i, grid, newGrid);
		printArray(i, grid);
			
	}
	
	return 0;
}

