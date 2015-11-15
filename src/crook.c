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

#define UP_KEY    14
#define DOWN_KEY  15
#define LEFT_KEY  16
#define RIGHT_KEY 17

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

	int x = maxx / 2, y = maxy / 2;

	gotoxy(x, y);
	putchar('@');

	int key;
	bool playing = true;

	while(playing) {
		key = getkey();

		cls();

		switch(key) {
		case UP_KEY:
			// Move UP if permitted
			if (y > 1) {
				y--;
			}

			gotoxy(7, maxy);
			printf("UP_KEY");
			break;
		case RIGHT_KEY:
			// Move RIGHT if permitted
			if (x < maxx) {
				x++;
			}

			gotoxy(7, maxy);
			printf("RIGHT_KEY");
			break;
		case DOWN_KEY:
			// Move DOWN if permitted
			if (y < maxy) {
				y++;
			}

			gotoxy(7, maxy);
			printf("DOWN_KEY");
			break;
		case LEFT_KEY:
			// Move LEFT if permitted
			if (x > 1) {
				x--;
			}

			gotoxy(7, maxy);
			printf("LEFT_KEY");
			break;
		case ESCAPE_KEY:
			playing = false;
			break;
		default:
			break;
		}

		gotoxy(1, maxy);
		printf("%d %d", x, y);

		gotoxy(x, y);

		putchar('@');
	}

	cls();
	printf("RIP Player 1...\n");

	showcursor();
	getch();
	cls();

	return 0;
}
