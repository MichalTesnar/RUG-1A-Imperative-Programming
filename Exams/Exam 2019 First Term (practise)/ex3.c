#include <stdio.h>
#include <stdlib.h>

int checkSolved(int x, int y, int arr[x][y]){
	int freeStacks = 3;
	for(int i = 0; i < x; i++){
		if(arr[i][0] != 0){
			freeStacks -= 1;
		}
	}
	//printf("%i %i\n", arr[1][0], freeStacks);
	return (arr[0][0] == 0 && freeStacks == 2);
}

void print2Darr(int x, int y, int arr[x][y]){
	printf("\n");
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			printf("%i ", arr[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int discs, moves;
	scanf("%i %i", &discs, &moves);
	
	int stacks[3][discs];
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < discs; j++){
			stacks[i][j] = 0;
		}
	}
	
	for(int i = 0; i < discs; i++){
		stacks[0][i] = i+1;
	}
	
	//print2Darr(3, discs, stacks);
	
	
	int start, target;
	int illegal = 0;
	int amounts[3] = {discs-1, -1, -1};
	for(int i = 0; i < moves; i++){
		scanf("%i->%i", &start, &target);
		//printf("%i-%i ", start, target);
		
		int taken = stacks[start][amounts[start]];
		stacks[start][amounts[start]] = 0;
		if((amounts[target]!= -1) && (taken < stacks[target][amounts[target]])){
			//print2Darr(3, discs, stacks);
			//printf("%i %i\n", taken, stacks[target][amounts[target]]);
			printf("ILLEGAL MOVE %i\n", i+1);
			illegal = 1;
			break;
		}
		amounts[start] -= 1;
		amounts[target] += 1;
		stacks[target][amounts[target]] = taken;
		
		
		//print2Darr(3, discs, stacks);
		//printf("%i %i %i\n", amounts[0], amounts[1], amounts[2]);
	}
	
	//print2Darr(3, discs, stacks);
	
	if(!illegal){
		if(checkSolved(3, discs, stacks)){
			printf("SOLVED\n");
		} else {
			printf("UNSOLVED\n");
		}
		
	}
	
	
	
	return 0;
}
