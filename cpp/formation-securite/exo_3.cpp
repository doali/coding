#include <assert.h>
#include <iostream>

/*
    création d'un buffer de N octets
*/
// void test(int i_length) {
void test(unsigned int i_length) { // SOLUTION valeur positive
  // assert(i_length > 0); // SOLUTION
    char* str;

    str = static_cast<char*>(malloc(i_length));
    assert(str != NULL);

    std::cout << "Vous avez créé un buffer de " << i_length <<" octets" << std::endl;
}

int main ()
{
    test(0);
    return 0;
}
