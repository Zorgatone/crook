/*
 * crook.c
 *
 *  Created on: 15 nov 2015
 *      Author: Zorgatone
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "rlutil/rlutil.h"

#define ESCAPE_KEY 0

#define UP_KEY    14;
#define DOWN_KEY  15;
#define LEFT_KEY  16;
#define RIGHT_KEY 17;

int main(void) {
	printf("Welcome to Crook!\n");

	getch();
	hidecursor();
	cls();

	int maxx = tcols(), maxy = trows();

	if (maxx < 0 || maxy < 0) {
		fprintf(stderr, "Terminal error!\n");

		exit(EXIT_FAILURE);
	}

	gotoxy(maxx / 2, maxy / 2.0);
	putchar('@');

	int key;
	bool playing = true;

	while(playing) {
		key = getkey();

		switch(key) {
		case ESCAPE_KEY:
			playing = false;
			break;
		}
	}

	cls();
	printf("RIP Player 1...\n");

	showcursor();
	getch();
	cls();

	return 0;
}
