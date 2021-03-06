#include <stdio.h>

/*
 * https://cs50.stackexchange.com/questions/8899/difference-between-char-and-char-in-c/35486
 *
 */

int main(void)
{
	char *str = "abc";
#ifdef LOG
	printf("%d:%s\n", __LINE__, str);
#endif

	char t_1[] = "abc";
#ifdef LOG
	printf("%d:%s\n", __LINE__, t_1);
#endif

	char t_2[3] = "abc";
#ifdef LOG
	printf("%d:%s\n", __LINE__, t_2);
#endif
	
	char t_3[] = {'a', 'b', 'c'};
#ifdef LOG
	printf("%d:%s\n", __LINE__, t_3);
#endif

	char t_4[3] = {'a', 'b', 'c'};
#ifdef LOG
	printf("%d:%s\n", __LINE__, t_4);
#endif

	char t_5[4] = {'a', 'b', 'c', '\0'};
#ifdef LOG
	printf("%d:%s\n", __LINE__, t_5);
#endif
	return 0;
}
