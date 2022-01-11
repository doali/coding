#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ_MSG 100 // message size


// --------------------------------------------------------------------------------
// static 
// --------------------------------------------------------------------------------
static char ERR_INFO[SZ_MSG];

static void handle_error(const char *msg)
{
	memset(ERR_INFO, 0, sizeof(char) * SZ_MSG);
	snprintf(ERR_INFO, SZ_MSG, "%u:%s|%s\n", __LINE__, __func__, msg);
	ERR_INFO[SZ_MSG] = '\0',
	perror(ERR_INFO);
	exit(-1);
}

static void str(const char *msg)
{
	printf("Message:%s\n", msg);
}

// --------------------------------------------------------------------------------
// type
// --------------------------------------------------------------------------------
typedef void (*p_f)(const char *);

typedef struct
{
	char msg[SZ_MSG];
	p_f to_str;
} Titi;

// --------------------------------------------------------------------------------
// methods
// --------------------------------------------------------------------------------
void Titi_to_str(Titi * const t)
{
	if (NULL == t)
	{
		handle_error("NULL pointer\n");
	}

	t->to_str(t->msg);
}

void Titi_init(Titi * const t)
{
	memset(t, 0, sizeof(Titi));
}

Titi *Titi_new(const char *msg)
{
	Titi *t = malloc(sizeof(Titi));
	if (NULL == t) 
	{
		perror("malloc failed\n");
		exit(1);
	}
	
	Titi_init(t);
	t->to_str = &str;

	strcpy(t->msg, msg);

	return t;
}

void Titi_free(Titi * const t)
{
	free(t);
}

// --------------------------------------------------------------------------------
// entry point
// --------------------------------------------------------------------------------
int main()
{
	Titi *t = Titi_new("Hello, I could be an object :-)");
	Titi_to_str(t);
	Titi_free(t);
	
	Titi_to_str(NULL);

	return 0;
}
