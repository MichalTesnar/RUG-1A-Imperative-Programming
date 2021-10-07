/*
 * file: airports.c
 * 
 * author: Michal Tešnar (m.tesnar@student.rug.nl)
 * 
 * Description: Program answers YES or NO depending whether a trip through
 * given airports, with given maximum amount of runways and given number of
 * visits in general can be done. Given are also runways from given airports
 * to other airports and the order in which we want to visit the cities.
 */


#include <stdio.h>

//returns 1 if we can travel from given startpoint in a given direction
int canTravelTo(int airports, int maximumRunways, int airportDestinations[airports][maximumRunways], int start, int direction){
	for(int i = 0; i < maximumRunways; i++){
		if(direction == airportDestinations[start][i]){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char **argv){
	
	int airports, maximumRunways, visits; //input variables
	scanf("%i %i %i", &airports, &maximumRunways, &visits);
	
	//array of possible destinations from given airports and their input from user
	int airportDestinations[airports][maximumRunways];
	for(int i = 0; i < airports; i++){
		for(int j = 0; j < maximumRunways; j++){
			scanf("%i", &airportDestinations[i][j]);
		}
	}
	
	//input first station
	int start, direction;
	scanf("%i", &start);
	
	//for given amount of visits we want to make we search of connection between two stations is possible
	for(int i = 1; i < visits; i++){
		scanf("%i", &direction);
		//if it is possible, change the start location and get another input otherwise end program
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

