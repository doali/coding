#include <stdio.h>
#include <time.h>

typedef struct clock Clock;

static void fn_clock(Clock *);
static void fn_cal(Clock *);
static void fn_id(Clock *);

struct clock
{
	char id[20];
	time_t time;
	void (*identity)(Clock *);
	void (*talk)(Clock *);
	void (*cal)(Clock *);
} o_clock = {
	.id = "Clock",
	.identity = fn_id,
	.talk = fn_clock,
	.cal = fn_cal};

void fn_id(Clock *clock)
{
	printf("%s\n", clock->id);
}

void fn_clock(Clock *clock)
{
	time(&(clock->time));
	printf("- %ld\n", clock->time);
}

void fn_cal(Clock *clock)
{
	printf("- %s", ctime(&clock->time));
}

int main(void)
{
	o_clock.identity(&o_clock);
	o_clock.talk(&o_clock);
	o_clock.cal(&o_clock);

	return 0;
}
