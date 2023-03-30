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

void draw_circle(unsigned int x, unsigned int y, unsigned int r, void (*draw)(unsigned int, unsigned int))
{
	const float PI = acos(-1);
	unsigned int precision = pow(2, 8);
	unsigned int c_x = (COLS - 1) / 2;
	unsigned int c_y = (LINES - 1) / 2;

	unsigned int elastic = r;
	for (; elastic < r + 20; elastic++)
	{
		// clear(); // clear screen
		for (unsigned int step = 0; step < precision; step++)
		{
			move(y, x);
			addch('o');
			x = c_x + elastic * cos(step * (2 * PI / precision));
			y = c_y + elastic * sin(step * (2 * PI / precision));
			refresh();
		}
		usleep(50000);
	}
}

int main(void)
{
	initscr();

	printw("Circle drawing"); // comment clear() to see this message

	draw_circle(70, 30, (LINES - 1) / 6, NULL);
	getch(); // hit a key to exit

	endwin();

	printf("LINES:%d\n", LINES);
	printf("COLS:%d\n", COLS);

	return 0;
}
