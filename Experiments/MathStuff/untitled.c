/*
 * untitled.c
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
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	//defining variables
	int x = 10;
	const int NUM = 3; //can't be modified
	float y = 8.888;
	
	
	//different printing statements
	printf("%d, %f, %d\n", x, y, NUM);
	
	printf("%d\n", NUM);
	
	printf("%f\n", pow(x, y));
	
	printf("%f\n", sqrt(x));
	
	printf("%f, %f\n", ceil(y), floor(y));
	
	//bools do not exist
	printf("%d\n", (x==x));
	
	return 0;
}

