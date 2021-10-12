/*
 * file: ***nameOfTheProgram***.c
 * 
 * author: Michal Tešnar (S4740556, m.tesnar@student.rug.nl)
 * 
 * Description: ***add here***
 */


#include <stdio.h>

int isInOrder(int size, char arr[size]){
	for(int i = 0; i < size-1; i++){
		//printf("%c %c\n", arr[i], arr[i+1]);
		if(arr[i]>arr[i+1]){
			return 0;
		}
	}
	
	return 1;
}

int main(int argc, char **argv){
	char sss[26];
	char command[4];
	int place1, place2;
	
	scanf("%s", sss);
	
	
	//printf("%s %i %i %c\n", command, place1, place2, command[1]);
	
	//char temporary;
	scanf("%s", command);
	
	
	while(command[1]!='t'){
		scanf("%i %i", &place1, &place2);
		
		char temporary = sss[place1];
		sss[place1] = sss[place2];
		sss[place2] = temporary;
		scanf("%s", command);
		
		//printf("%s %i %i %c\n", command, place1, place2, command[1]);
	}
	
	//printf("%s %i\n", sss, isInOrder(26, sss));
	
	if(isInOrder(26, sss)==1){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	//printf("%s %i %i", command, place1, place2);
	return 0;
}

