/*
 * structures.c
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
#include <string.h>

struct Person {
	char name[20];
	int age;
	int BSN;
	float weight;
};



int main(int argc, char **argv)
{
	
	struct Person Michal;
	
	strcpy(Michal.name, "Michal");
	Michal.age=20;
	Michal.BSN=31227;
	Michal.weight=73.5;
	
	struct Person Eva;
	
	strcpy(Eva.name, "Eva");
	Eva.age=21;
	Eva.BSN=31127227;
	Eva.weight=50.6;
	int x = 10;
	
	do{
	printf("%i\n", Michal.age);
	printf("%i\n", Eva.age);
	printf("%i\n", x);
	x++;
	}while(x<20);
	return 0;
}

