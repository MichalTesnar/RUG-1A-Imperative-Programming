/*
 * printExam.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 *
 * This program prints out the number of pages of paper to print
 * on both sides for an exam with given amount of people and
 * pages per person.
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int n = 0; //number of pages per student
	int m = 0; //number of attending students
	
	scanf("%i %i", &n, &m); //getting variable values
	
	/* If the number of pages is odd, then we add one
	 * for the empty page at the end of the exam.
	 */
	
	if(n%2 == 1){
		n += 1;
	}
		
	/*
	 * We compute the result as number of pages divided by two
	 * and multiply by the number of students.
	 */
	 	
	int result = n/2*m;
	
	printf("%i\n", result);
	
	return 0;
}

