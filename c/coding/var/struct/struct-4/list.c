#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#if defined(TEST)
#define TEST_FUNC_NAME printf("==== TEST ========================== [%s]\n", __func__)
#endif

// ==== list

struct cell
{
    unsigned long _id;
    void *_data;
    struct cell *_next;
};

typedef struct cell *List, Cell;

void init_list_empty(List p_list)
{
    p_list = NULL;
}

Cell *init_cell(Cell *p_cell, unsigned long p_val)
{
    p_cell->_id = p_val;
    p_cell->_data = NULL;
    p_cell->_next = NULL;

    return p_cell;
}

List add_cell(List *p_list, Cell *p_cell)
{
    if (*p_list == NULL)
    {
        *p_list = p_cell;
        return *p_list;
    }

    Cell *l_cell = *p_list;
    while (l_cell->_next != NULL)
        l_cell = l_cell->_next;

    l_cell->_next = p_cell;
    return *p_list;
}

List print_list(List *p_list)
{
    printf("[");

    Cell *l_cell = *p_list;

    if (l_cell != NULL)
    {
        printf("%ld", l_cell->_id);
    }

    while ((l_cell = l_cell->_next) != NULL)
    {
        printf(" %ld", l_cell->_id);
    }

    printf("]\n");

    return *p_list;
}

int size_list(List *list)
{
    int size = 0;

    if (*list == NULL)
    {
        return 0;
    }

    List l_list = *list;

    ++size;
    while ((l_list = l_list->_next) != NULL)
    {
        ++size;
    }

    return size;
}

Cell *cell_list(List *list, unsigned long nth)
{
    if (*list == NULL || nth == 0)
    {
        return NULL;
    }

    unsigned long l_nth = 1;
    for (List l_list = *list; l_list != NULL; l_list = l_list->_next)
    {
        if (l_nth == nth)
        {
            return l_list;
        }
        ++l_nth;
    }

    return NULL;
}

void map_list(List *list, void (*p_f)(unsigned long *))
{
    if (*list == NULL)
    {
        return;
    }

    for (List l_list = *list; l_list != NULL; l_list = l_list->_next)
    {
        p_f(&l_list->_id);
    }
}

// ==== test

#if defined(TEST)
static void test_init_list_empty()
{
    TEST_FUNC_NAME;
    List l_list = NULL;
    init_list_empty(l_list);

    assert(l_list == NULL);
}

static void test_add_cell()
{
    TEST_FUNC_NAME;
    List l_list = NULL;
    init_list_empty(l_list);

    Cell c0, c1, c2, c3;
    init_cell(&c0, 0);
    init_cell(&c1, 1);
    init_cell(&c2, 2);
    init_cell(&c3, 3);

    add_cell(&l_list, &c0);
    add_cell(&l_list, &c1);
    add_cell(&l_list, &c2);
    add_cell(&l_list, &c3);

    print_list(&l_list);
}

static void test_size_list()
{
    TEST_FUNC_NAME;
    List l_list = NULL;
    init_list_empty(l_list);
    assert(size_list(&l_list) == 0);

    Cell c0, c1, c2, c3;
    init_cell(&c0, 0);
    init_cell(&c1, 1);
    init_cell(&c2, 2);
    init_cell(&c3, 3);

    add_cell(&l_list, &c0);
    assert(size_list(&l_list) == 1);
    add_cell(&l_list, &c1);
    assert(size_list(&l_list) == 2);
    add_cell(&l_list, &c2);
    assert(size_list(&l_list) == 3);
    add_cell(&l_list, &c3);
    assert(size_list(&l_list) == 4);
}

static void test_map_list()
{
    TEST_FUNC_NAME;
    void multiply(unsigned long *op)
    {
        *op = *op * 2;
    }

    List l_list = NULL;
    init_list_empty(l_list);

    Cell c0, c1, c2, c3;
    init_cell(&c0, 10);
    init_cell(&c1, 11);
    init_cell(&c2, 22);
    init_cell(&c3, 33);

    add_cell(&l_list, &c0);
    add_cell(&l_list, &c1);
    add_cell(&l_list, &c2);
    add_cell(&l_list, &c3);

    print_list(&l_list);

    map_list(&l_list, multiply);

    print_list(&l_list);
}

static void test_cell_list()
{
    TEST_FUNC_NAME;

    void print_cell(Cell * cell)
    {
        if (cell != NULL)
        {
            printf("Cell:%p\n", cell);
            printf("  _id:%ld\n", cell->_id);
            printf("  _next:%p\n", cell->_next);
        }
    }

    List l_list = NULL;
    init_list_empty(l_list);

    Cell c0, c1, c2, c3;
    init_cell(&c0, 10);
    init_cell(&c1, 11);
    init_cell(&c2, 22);
    init_cell(&c3, 33);

    add_cell(&l_list, &c0);
    add_cell(&l_list, &c1);
    add_cell(&l_list, &c2);
    add_cell(&l_list, &c3);

    print_list(&l_list);

    const int size_l_list = size_list(&l_list);
    assert(size_l_list == 4);
    for (int nth = 1; nth <= size_l_list; ++nth)
    {
        Cell *cell = cell_list(&l_list, nth);
        print_cell(cell);
    }

    print_list(&l_list);
}

static void test()
{
    test_init_list_empty();
    test_add_cell();
    test_size_list();
    test_map_list();
    test_cell_list();
}
#endif

int main(int argc, char **argv)
{
#if defined(TEST)
    test();
#endif
    return EXIT_SUCCESS;
}