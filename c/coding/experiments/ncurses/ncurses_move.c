// =============================================================================
// Example modified from
// https://arnaud-feltz.developpez.com/tutoriels/ncurses/?page=premier_pas
// =============================================================================

#include <ncurses.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

typedef struct element s_element;

struct element
{
	int x;
	int y;
	void (*move_element)(s_element *, int, int);
};

static void update_move_element(s_element *element, int x, int y)
{
	element->x += x;
	element->y += y;
	move(element->y, element->x);
}

void init_element(s_element *element, int x, int y)
{
	element->x = x;
	element->y = y;
	element->move_element = update_move_element;
}

static void handle_move(s_element *element)
{
	int key_hitten = 0;

	while ((key_hitten = getch()) != 'q')
	{
		// clear_info();
		switch (key_hitten)
		{
		case KEY_UP:
			element->move_element(element, 0, -1);
			break;
		case KEY_RIGHT:
			element->move_element(element, 1, 0);
			break;
		case KEY_DOWN:
			element->move_element(element, 0, 1);
			break;
		case KEY_LEFT:
			element->move_element(element, -1, 0);
			break;
		default:
			printw("Arrow key expected");
			break;
		}
		printw("o");
	}
}

static void do_center()
{
	move((LINES - 1) / 2, (COLS - 1) / 2);
}

int main(void)
{
	s_element cursor;

	initscr();
	keypad(stdscr, TRUE);

	do_center();
	init_element(&cursor, getcurx(stdscr), getcury(stdscr));
	handle_move(&cursor);

	endwin();

	return 0;
}
