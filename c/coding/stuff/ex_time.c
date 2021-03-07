#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int write_file(const char *filename)
{
	FILE *file = fopen(filename, "w");

	if (file == NULL) 
	{
		perror("");
		exit(EXIT_FAILURE);
	}

	long int t = time(NULL);
	struct tm *lt = localtime(&t);
	int ret = fprintf(file, "Time [%ld] [%02u:%02u:%02u]\n", t, lt->tm_hour, lt->tm_min, lt->tm_sec);

	fflush(file);
	fclose(file);
	
	return ret;
}

int read_file(const char* filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL) 
	{
		perror("");
		exit(EXIT_FAILURE);
	}

	char c ='\0';
	while ((c = getc(file)) != EOF)
	{
		printf("%c", c);
	}

	fclose(file);

	return 1;
}

int main(int nargs, char** vargs)
{	
	const char* filename = "/tmp/tutu.txt";

	int ret = 0;

	ret = write_file(filename);
	ret = read_file(filename);

	return ret;
}
