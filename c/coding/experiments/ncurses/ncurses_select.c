// =============================================================================
// Example modified from
// https://arnaud-feltz.developpez.com/tutoriels/ncurses/?page=premier_pas
// =============================================================================

#include <ncurses.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>
#include <locale.h>
#include <sys/select.h>
#include <time.h>
#include <stdlib.h>

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

static void init_element(s_element *element, int x, int y)
{
	element->x = x;
	element->y = y;
	element->move_element = update_move_element;
}

static void do_center()
{
	move((LINES - 1) / 2, (COLS - 1) / 2);
}

enum Action
{
	QUIT,
	CONTINUE
};

static int lireAction(s_element *element)
{
	struct timeval timeout = {0, 1000000 / 25};
	fd_set rfds;
	int ret;
	int key_hitten = 0;

	FD_ZERO(&rfds);
	FD_SET(fileno(stdin), &rfds);

	do
	{
		ret = select(1, &rfds, NULL, NULL, &timeout);
		if (ret <= 0)
		{
			break;
		}

		key_hitten = getch();
	} while (true);

	switch (key_hitten)
	{
	case KEY_LEFT:
		addstr("\u2190");
		element->move_element(element, -1, 0);
		return CONTINUE;
	case KEY_UP:
		addstr("\u2191");
		element->move_element(element, 0, -1);
		return CONTINUE;
	case KEY_RIGHT:
		addstr("\u2192");
		element->move_element(element, 1, 0);
		return CONTINUE;
	case KEY_DOWN:
		addstr("\u2193");
		element->move_element(element, 0, 1);
		return CONTINUE;
	case 'q':
		return QUIT;
	default:
		return CONTINUE;
		break;
	}

	return QUIT;
}

static void show_time()
{
	time_t t = time(NULL);
	struct tm *ltm = localtime(&t);
	int y, x;
	getyx(stdscr, y, x);
	move(0, 0);
	printw("%d:%d:%d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
	move(y, x);
	refresh();
}

static void draw_rect(int height, int width)
{
	int x, y;
	getyx(stdscr, y, x);
	move(2, 0);
	hline('#', (COLS - 1) / 4 + 1);
	move(21, 0);
	hline('#', (COLS - 1) / 4 + 1);

	move(3, 0);
	vline('#', 18);
	move(3, (COLS - 1) / 4);
	vline('#', 18);
	move(y, x);
}

static void draw_ball(int *x, int *y, int *dir_x, int *dir_y)
{
	static unsigned int nb_move = 0;
	int bck_x, bck_y;
	getyx(stdscr, bck_y, bck_x);

	if (*x == (COLS - 1) / 4)
	{
		*dir_x = -1;
	}
	else if (*x == 0)
	{
		*dir_x = 1;
	}

	if (*y == 2)
	{
		*dir_y = 1;
	}
	else if (*y == 21)
	{
		*dir_y = -1;
	}
	*y += *dir_y;
	*x += *dir_x;
	move(*y, *x);
	addch('*');

	if (nb_move++ == 200)
	{
		nb_move = 0;
		clear();
	}

	move(bck_y, bck_x);
	refresh();
}

int main(void)
{
	s_element cursor;

	setlocale(LC_ALL, "");

	initscr();
	keypad(stdscr, TRUE);

	do_center();
	init_element(&cursor, getcurx(stdscr), getcury(stdscr));

	srand(time(NULL));
	int x = rand() % ((COLS - 1) / 4);
	int y = rand() % 21;
	int dir_x = 1, dir_y = 1;
	while (lireAction(&cursor) == CONTINUE)
	{
		show_time();
		draw_rect(0, 0);
		draw_ball(&x, &y, &dir_x, &dir_y);
	}

	endwin();

	return 0;
}
