/*
 * file: ***nameOfTheProgram***.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: ***add here***
 */


#include <stdio.h>

//prints the values in an array
void print2DArray(int sizeX, int sizeY, int array[sizeX][sizeY]){
	for(int i = 0; i < sizeX; i++){
		for(int j = 0; j < sizeY; j++){
			printf("%i ", array[i][j]);
		}
		printf("\n");
	}
}

int canTravelTo(int airports, int maximumRunways, int airportDestinations[airports][maximumRunways], int start, int direction){
	for(int i = 0; i < maximumRunways; i++){
		//printf("LOLEC %i %i\n", direction, airportDestinations[start][i]);
		if(direction == airportDestinations[start][i]){
			return 1;
		}
	}
	
	return 0;
}

int main(int argc, char **argv){
	
	int airports, maximumRunways, visits; //input
	scanf("%i %i %i", &airports, &maximumRunways, &visits);
	
	int airportDestinations[airports][maximumRunways];
	for(int i = 0; i < airports; i++){
		for(int j = 0; j < maximumRunways; j++){
			scanf("%i", &airportDestinations[i][j]);
		}
	}
	
	/*int airportDestinations[5][3] = {
		{1,2,3},
		{2,3,-1},
		{0,1,-1},
		{0,1,2},
		{1,2,-1}
		};
	//print2DArray(airports, maximumRunways, airportDestinations);

	printf("%i", canTravelTo(airports, maximumRunways, airportDestinations, 0, 1));
	printf("%i", canTravelTo(airports, maximumRunways, airportDestinations, 2, 1));
	printf("%i", canTravelTo(airports, maximumRunways, airportDestinations, 2, 3));
	*/
	
	int start, direction;
	scanf("%i", &start);
	
	for(int i = 1; i < visits; i++){
		scanf("%i", &direction);
		//printf("%i", direction);
		if(canTravelTo(airports, maximumRunways, airportDestinations, start, direction) == 1){
			start = direction;
		} else {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}

