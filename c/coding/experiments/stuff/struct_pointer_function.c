
#include <stdio.h>

struct op
{
        int(*sum)(int, int);
        int(*mul)(int, int);
};

int add(int a, int b)
{
        return a + b;
}

int mul(int a, int b)
{
        return a * b;
}

int main(int *n, char **v)
{
        struct op s_op = {
                add,
                mul
        };

        int res = 0;
        int op_a, op_b;
        op_a = 10;
        op_b = 1;
        res = s_op.sum(op_a, op_b);

        printf("%d %d -> %d\n", op_a, op_b, res);

        return 0;
}
