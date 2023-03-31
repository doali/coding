// =============================================================================
// Example modified from
// https://arnaud-feltz.developpez.com/tutoriels/ncurses/?page=premier_pas
// =============================================================================

#include <ncurses.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

static void draw_point(unsigned int x, unsigned int y)
{
	move(y, x);
	addch('#');
}

static void clear_from_line_1()
{
	move(1, 0);
	clrtobot(); // clear until the last line
}

void draw_circle(unsigned int x, unsigned int y, unsigned int r, void (*draw)(unsigned int, unsigned int))
{
	const float PI = acos(-1);
	unsigned int precision = pow(2, 8);
	unsigned int l_x = 0;
	unsigned int l_y = 0;

	unsigned int elastic = r;
	unsigned int max = (r + LINES - 1) / 2;
	for (; elastic < max; elastic++)
	{
		// clear(); // clear screen
		clear_from_line_1();
		for (unsigned int step = 0; step < precision; step++)
		{
			l_x = x + elastic * cos(step * (2 * PI / precision));
			l_y = y + elastic * sin(step * (2 * PI / precision));
			move(l_y, l_x);
			addch('.');
			refresh();
		}
		usleep(50000);
	}
}

int main(void)
{
	initscr();

	printw("Circle drawing"); // comment clear() to see this message or use clear_from_line_1()

	unsigned int c_x = (COLS - 1) / 2;
	unsigned int c_y = (LINES - 1) / 2;

	draw_circle(c_x, c_y, (LINES - 1) / 6, NULL);
	getch(); // hit a key to exit

	endwin();

	printf("LINES:%d\n", LINES);
	printf("COLS:%d\n", COLS);

	return 0;
}
