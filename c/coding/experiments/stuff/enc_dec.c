// -----------------------------------------------------------------------------
// gcc -Wall enc_dec.c -o enc_dec
// valgrind ./enc_dec
// -----------------------------------------------------------------------------
#include <stdio.h>

static char data[4] = {
	0xAA,
	0xFF,
	0xFF,
	0xFF
};

typedef void(*encode)(char*);
typedef void(*decode)(char*);

typedef struct
{
	void(*enc)(char*);
	void(*dec)(char*);
} prot;

void prot_init(prot* s, encode f_e, decode f_d)
{
	s->enc = f_e;
	s->dec = f_d;
}

void f_encode(char* buf)
{
	buf[0] = 0xFF;
}

void f_decode(char* buf)
{
	buf[0] = 0xAA;
}

void check(char* buf)
{
	printf("%x\n", *buf);
}

// -----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	check(data);

	prot s;
	prot_init(&s, f_encode, f_decode);

	s.enc(data);
	check(data);

	s.dec(data);
	check(data);

	return 0;
}
