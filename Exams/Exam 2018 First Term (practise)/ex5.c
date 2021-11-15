#include <stdio.h>
#include <stdlib.h>

int recursive(char *pattern, char *string, int patI, int strI) {
	//base case, reached end of both strings
	if(pattern[patI] == '\0' && string[strI] == '\0'){
		return 1;
	}
	
	if(pattern[patI] == string[strI] && pattern[patI+1] != '?'){
		//printf("OK\n");
		return recursive(pattern, string, patI + 1, strI + 1);
	}
	
	if(pattern[patI+1] == '?'){
		//printf("also OK\n");
		return (pattern[patI] == string[strI] && recursive(pattern, string, patI + 2, strI + 1))
		|| recursive(pattern, string, patI + 2, strI);
	}
	
	return 0;
}

int isMatch(char *pattern, char *string) {
	return recursive(pattern, string, 0, 0);
}


int main(int argc, char *argv[]) {
	char pattern[30], string[30];
	scanf("%s %s", pattern, string);
	if (isMatch(pattern, string) == 0){
		printf("NO ");
	}
	printf("MATCH\n");
	return 0;
}
