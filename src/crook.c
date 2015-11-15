/*
 * crook.c
 *
 *  Created on: 15 nov 2015
 *      Author: Zorgatone
 */

#include <stdio.h>
#include <stdlib.h>

#include "rlutil/rlutil.h"

int main(void) {
	printf("Welcome to Crook!\n");

	getch();
	cls();

	int maxx = tcols(), maxy = trows();

	if (maxx < 0 || maxy < 0) {
		fprintf(stderr, "Terminal error!\n");

		exit(EXIT_FAILURE);
	}

	gotoxy(maxx / 2, maxy / 2.0);
	putchar('@');

	while(getkey() != KEY_ESCAPE) {

	}

	cls();
	printf("#RIP Player1...\n");

	getch();
	cls();

	return 0;
}
