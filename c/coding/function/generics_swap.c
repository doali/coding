#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ============================================== TOOLS ==============================================
static void print_title(const char *p_pTitle)
{
	printf("\n\n========== %s ==========\n", p_pTitle);
}

static void print_sub_title(const char *p_pTitle)
{
	printf("\n---------- %s ----------\n", p_pTitle);
}

static void print_couple(int *p_pA, int *p_pB)
{
	printf("%5s|%p:%3d\n", "p_pA", p_pA, *p_pA);
	printf("%5s|%p:%3d\n", "p_pB", p_pB, *p_pB);
}

static void print_addr(void *p_pA) // generic
{
	printf("%p:%p\n", p_pA, *(void **)p_pA);
}

static void print_addr_value_int(const char *msg, void *p_pA)
{
	printf("%5s|%p:%p:%3d\n", msg, p_pA, *(void **)p_pA, **((int **)p_pA));
}

static void call_function(const char* p_pLabel, void(*f_test)())
{
	printf("------> %s\n", p_pLabel);
	f_test();
	printf("<------ %s\n", p_pLabel);
}

static void print_in(const char* p_pMsg)
{
	printf("------> %s\n", p_pMsg);
}

static void print_out(const char* p_pMsg)
{
	printf("<------ %s\n", p_pMsg);
}
// ============================================== SWAP ===============================================
static void spe_swap(int *p_pA, int *p_pB)
{	
	print_in("spe_swap");
	print_couple(p_pA, p_pB);

	int l_Tmp = *p_pA;
	*p_pA = *p_pB;
	*p_pB = l_Tmp;

	print_couple(p_pA, p_pB);
	print_out("spe_swap");
}

static void gen_swap_addr(void *p_pA, void *p_pB) // generic
{
	print_in("gen_swap_addr");	
	print_addr(p_pA);
	print_addr(p_pB);
	print_addr_value_int("p_pA", p_pA);
	print_addr_value_int("p_pB", p_pB);

	printf("...swap addr...\n");

	void *l_pTmp;
	l_pTmp = *(void **)p_pA;
	*(void **)p_pA = *(void **)p_pB;
	*(void **)p_pB = l_pTmp;

	print_addr_value_int("p_pA", p_pA);
	print_addr_value_int("p_pB", p_pB);
	print_addr(p_pA);
	print_addr(p_pB);
	print_out("gen_swap_addr");

	/*
	Changement uniquement des addresses sur lesquelles on pointe
	@pointeur A | @pointée LA         ; gen_swap_addr() ; @pointeur A | @pointée LB
	...
	@pointée LA | valeur entière VA   ; gen_swap_addr() ; @pointée LB | valeur entière VB
	*/
}

static void gen_swap_memcpy(void *p_pA, void *p_pB, size_t p_Sz) // generic
{
	print_in("gen_swap_memcpy");
	print_addr(p_pA);
	print_addr(p_pB);
	print_addr_value_int("p_pA", p_pA);
	print_addr_value_int("p_pB", p_pB);

	printf("...swap memcpy...\n");

	void *l_pTmp = malloc(p_Sz);
	memcpy(l_pTmp, *(void **)p_pA, p_Sz);
	memcpy(*(void **)p_pA, *(void **)p_pB, p_Sz);
	memcpy(*(void **)p_pB, l_pTmp, p_Sz);

	free(l_pTmp);

	print_addr_value_int("p_pA", p_pA);
	print_addr_value_int("p_pB", p_pB);
	print_addr(p_pA);
	print_addr(p_pB);
	print_out("gen_swap_memcpy");

	/*
	Changement des valeurs aux addresses sur lesquelles on pointe
	@pointeur A | @pointée LA         ; gen_swap_memcpy() ; @pointeur A | @pointée LA
	...
	@pointée LA | valeur entière VA   ; gen_swap_memcpy() ; @pointée LA | valeur entière VB <== changement de la valeur !!!
	*/
}

static void gen_swap_memcpy_final(void *p_pA, void *p_pB, size_t p_Sz) // generic
{
	print_in("gen_swap_memcpy_final");
	printf("...swap memcpy final...\n");

	void *l_pTmp = malloc(p_Sz);
	memcpy(l_pTmp, p_pA, p_Sz);
	memcpy(p_pA, p_pB, p_Sz);
	memcpy(p_pB, l_pTmp, p_Sz);

	free(l_pTmp);

	print_out("gen_swap_memcpy_final");

	/*
	Changement des valeurs aux addresses sur lesquelles on pointe
	@pointeur A | @pointée LA         ; gen_swap_memcpy() ; @pointeur A | @pointée LA
	...
	@pointée LA | valeur entière VA   ; gen_swap_memcpy() ; @pointée LA | valeur entière VB <== changement de la valeur !!!
	*/
}

// ============================================== TESTS ==============================================
static void test_spe_swap()
{
	int l_A = 1;
	int l_B = 2;

	print_couple(&l_A, &l_B);
	spe_swap(&l_A, &l_B);
	print_couple(&l_A, &l_B);
}

static void test_gen_swap_addr()
{	
	int l_A = 10;
	int l_B = 20;

	int *l_pA = &l_A;
	int *l_pB = &l_B;

	print_couple(l_pA, l_pB);
	gen_swap_addr(&l_pA, &l_pB);
	print_couple(l_pA, l_pB);
}

static void test_gen_swap_memcpy()
{
	int l_A = 100;
	int l_B = 200;

	int *l_pA = &l_A;
	int *l_pB = &l_B;

	print_couple(l_pA, l_pB);
	gen_swap_memcpy(&l_pA, &l_pB, sizeof(int));
	print_couple(l_pA, l_pB);
}

static void test_gen_swap_memcpy_final()
{
	int l_A = 100;
	int l_B = 200;

	int *l_pA = &l_A;
	int *l_pB = &l_B;

	print_couple(l_pA, l_pB);
	gen_swap_memcpy_final(l_pA, l_pB, sizeof(int));
	print_couple(l_pA, l_pB);
}

// ============================================== MAIN ===============================================
int main(int argc, char **argv)
{
	print_title("Specific");
	call_function("test_spe_swap", test_spe_swap);

	print_title("Generic");

	print_sub_title("addr");
	call_function("test_gen_swap_addr", test_gen_swap_addr);	

	print_sub_title("memcpy");
	call_function("test_gen_swap_memcpy", test_gen_swap_memcpy);

	print_sub_title("memcpy final");
	call_function("test_gen_swap_memcpy_final", test_gen_swap_memcpy_final);

	return 0;
}
