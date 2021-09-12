/*
 * functions.c
 * 
 * Copyright 2021 Michal Tešnar <michal.tesnar007@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>


//function prototypes
long fact(int num);

long factorial(long x);

int main(int argc, char **argv)
{
	long x = 5;
	for(x=1;x<25;x++){
		printf("The factorial of %ld is %ld, %ld.\n",x, factorial(x), fact(x));
	}
	return 0;
}

long factorial(long x){
	
	long answer = 1;
	
	while(x!=1){
		answer *=x;
		x--;
		}
	
	return answer;
	}

long fact(int num){
		
	if(num!= 1){
		num = num*fact(num-1);
	}
	
	return num;
}

