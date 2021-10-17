#include <stdio.h>

int randomWalk(int startX, int startY, int endX, int endY, int steps, int counter){
	//printf("%i %i %i %i\n", startX, startY, steps, counter);
	if(steps == 0){
		return(startX == endX && startY == endY);
	}
	counter += randomWalk(startX + 1, startY, endX, endY, steps - 1, counter) +
	randomWalk(startX - 1, startY, endX, endY, steps - 1, counter) +
	randomWalk(startX, startY + 1, endX, endY, steps - 1, counter) +
	randomWalk(startX, startY - 1, endX, endY, steps - 1, counter);
	return counter;
}

int main(int argc, char **argv){
	int startX = 0, startY = 0, endX = 2, endY = 2;
	int steps = 4;
	int i = randomWalk(startX, startY, endX, endY, steps, 0);
	printf("%i\n", i);
	return 0;
}
