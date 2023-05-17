#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SZ_ALEA_MSG 4

typedef void (*action)(const char *);

static char *alea_msg[SZ_ALEA_MSG] = {"coucou", "fait beau", "brain eich", "K&R"};

void wait();

const char *alea_saying()
{
	unsigned int index = random() % SZ_ALEA_MSG;
	return alea_msg[index];
}

void loop(unsigned int *it, action f)
{
	static unsigned int curr = 0;
	const char *curr_msg = alea_saying();
	f(curr_msg);
	if (curr >= *it)
		return;
	++curr;
	wait();
	loop(it, f);
}

void titi(const char *msg)
{
	printf("titou:%s\n", msg);
}

void wait()
{
	struct timeval tv = {.tv_sec = 1, .tv_usec = 0};
	select(1, NULL, NULL, NULL, &tv);
}

int main(int argc, char **argv)
{
	unsigned int max = 10;
	loop(&max, titi);

	return EXIT_SUCCESS;
}
