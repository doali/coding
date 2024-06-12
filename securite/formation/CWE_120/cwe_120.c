#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct m_buf {
    char buf[100];
    void (*ext_free)(void*);
};

/*
** This is a function, let say anywhere in the kernel, we want to execute
*/
void _got_root(void) { printf("Wootwoot, you are now root!\n"); }

/*
** Init a m_buf struct, fill it with the data from user input and return it
*/
struct m_buf* init_m_buf(const char* const data) {
    struct m_buf* m;

    m = (struct m_buf*)malloc(sizeof(struct m_buf));
    assert(m != NULL);

    // unchecked copy
    // There we need to write the addresse of "_got_root" into m->ext_free
    strcpy(m->buf, data);

    return (m);
}

/*
** This process the data inside buffer, a print is fine
*/
void process_m_buf(struct m_buf* m) { printf("%s\n", m->buf); }

/*
** Free the allocated buffer either by using the libc/free or your...
*/
void free_m_buf(struct m_buf* m) {
    if (m->ext_free) {
        (*(m->ext_free))(m);
    } else {
        free(m);
    }
}

/*
** help message
*/
void _usage(const char* const prog) {
    printf("Usage: %s <password>\n", prog);
    exit(0);
}

int32_t main(int32_t argc, char** argv) {
    struct m_buf* m;
    if (argc != 2) {
        _usage(argv[0]);
    }
    printf("sizeof(m_buf) : %ld\n", sizeof(struct m_buf));
    printf("adresse de _got_root : %p\n", _got_root);
    m = init_m_buf(argv[1]);

    process_m_buf(m);

    free_m_buf(m);

    return (0);
}