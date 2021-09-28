#include <stdio.h>

int manhattanDistance(int x1, int y1, int x2, int y2){
	int xDif = x1-x2;
	int yDif = y1-y2;
	if(xDif<0){
		xDif=-xDif;
	}
	if(yDif<0){
		yDif=-yDif;
	}
	return xDif+yDif;
}

int main(int argc, char **argv)
{
	int x1, y1, x2, y2; //input
	scanf("%i %i %i %i", &x1, &y1, &x2, &y2);
	printf("%i", manhattanDistance(x1, y1, x2, y2));
	return 0;
}
