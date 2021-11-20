#include <stdio.h>

#define INFO_CODE_START(msg) printf("<=== %s <===\n", msg)
#define INFO_CODE_STOP(msg) printf("===> %s ===.\n", msg)

// déclaration de la fonction
int add(int, int);

int main(int n, char** a)
{
	// cas 1 : pointeur sur fonction, usage classique
	INFO_CODE_START("cas 1");
	int (*pf)(int, int);
	pf = &add;
	int res = pf(3, 4);
	printf("res=%d\n", res);
	INFO_CODE_STOP("cas 1");

	// cas 2 : déclaration, définition de la fonction
	INFO_CODE_START("cas 2");
	int mul(int a, int b) 
	{
		return a * b;
	}

	pf = &mul;
	res = pf(4, 5);
	printf("res=%d\n", res);
	INFO_CODE_STOP("cas 2");

	// cas 3: déclaration, définition de la fonction fg
	// On aimerait écrire int(*)(int) ma_fonction(int)
	// mais la syntaxe correcte est int(*ma_fonction(int))(int)
	INFO_CODE_START("cas 3");
	int (*fg(int a))(int)
	{
		int  g(int z)
		{
			return a + z;
		}
		return g; // <= pointeur sur fonction : int(*<pointeur_sur_fonction>)(int)
	}

	res = fg(10)(3); // fg(10) renvoie une fonction que l'on appelle sur 3
	printf("res=%d\n", res);
	INFO_CODE_STOP("cas 3");

	// cas 4 : utilisation d'un typedef pour davantage de clarté
	INFO_CODE_START("cas 4");
	typedef int (*p_fg)(int);
	p_fg fg_10 = fg(10);
	res = fg_10(8);
	printf("res=%d\n", res);

	for (int i = 0; i < 10; i++)
	{
		printf("\t- res=%d\n", fg_10(i));
	}
	INFO_CODE_STOP("cas 4");

	return 0;
}

// définition
int add(int a, int b)
{
	return a + b;
}
