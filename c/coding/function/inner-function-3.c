#include <stdio.h>

#define INFO(MSG) printf("Message:%s\n", MSG)
#define INFO_NUMBER(NMB) printf("- value:%d\n", NMB)
#define INFO_ARRAY(INDEX, NMB) printf("Index:[%d], Increment:%d\n", INDEX, NMB)

typedef int(*p_f)(int);

int main(void)
{
	INFO("--- Inner function ---");

	p_f f(const int cst) {
		static int total = 0;
		total += cst;

		int increment(int valeur) {
			total += valeur;
			return total;
		}

		return increment;
	}

	p_f f_10 = f(10);
	int res = f_10(32);

	INFO_NUMBER(res);	

	int arr_increment[] = {1, 0, 7, -1};

	int index = 0;
	while (arr_increment[index] != -1)
	{
		res = f_10(arr_increment[index]);
		INFO_ARRAY(index, arr_increment[index]);	
		INFO_NUMBER(res);

		++index;
	}

	return 0;
}
