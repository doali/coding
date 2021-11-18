#include <iostream>
#include <stdio.h>
#include <string.h>

#define MSG_MAX 100

using namespace std;

void echo(char* msg) { printf("=> %s", msg); }

struct simple
{
        int a;
        char msg[MSG_MAX];
        void affiche(void)
        {
                std::cout << "methode" << std::endl;
        }
        void (*doudou)(void*);
} msg_simple;

namespace Test
{
namespace MyOp
{
        template <typename T>
        T op(T a, T b) { return a + b; }
}
}

class A
{
        int _i;
public:
        int getI() const;
        void setI(const int i)
        {
                this->_i = i;
        }

        A() { std::cout << "A()" << std::endl; }

        A(int i): _i(i) { std::cout << "A(int)" << std::endl; }

        virtual ~A()
        {
                std::cout << "~A()" << std::endl;
        }

        virtual void doSomething() const { std::cout << "A is doing something" << std::endl; }
};

class B : public A
{

public:
        B() : A() { std::cout << "B()" << std::endl; }

        B(int i): A(i) { std::cout << "B(int)" << std::endl; }

        virtual ~B()
        {
                std::cout << "~B()" << std::endl;
        }

        virtual void doSomething() const { std::cout << "B is doing something" << std::endl; }
};

int A::getI() const
{
        return _i;
}

void affiche_addresse(A *a)
{
        std::cout << a << std::endl;
}

void test()
{
        A a;
        affiche_addresse(&a);
        printf("=> %p\n", &a);
        a.setI(10);
        std::cout << a.getI() << std::endl;

        A b(11);
        affiche_addresse(&b);
        printf("=> %p\n", &b);
        std::cout << b.getI() << std::endl;

        A *c = new A(12);
        affiche_addresse(c);
        printf("=> %p\n", c);
        std::cout << c->getI() << std::endl;
        delete(c);
}

namespace X { namespace Y { namespace Z {
class Titi {};
}}}

using namespace X::Y;

int main(int nargs, char **argsv)
{
//      test();
//      cout << "Fin" << endl;
//
//      // operation char
//      char a = -10;
//      char b = 5;
//      char res = a - b;
//      printf("%d\n", res);
//
        A a;
        B b;
        A* t[] = {&a, &b};
        for (int e = 0; e < 2; e++)
        {
                t[e]->doSomething();
        }


        std::cout << "Operation +" << std::endl;
        int resi = Test::MyOp::op(1, 3);
        std::cout << "Res+ =" << resi << std::endl;

        std::cout << "Operation *" << std::endl;
        float resf = Test::MyOp::op(1.0, 2.0);
        std::cout << "Res* =" << resf << std::endl;

        Z::Titi();

        memset(&msg_simple, 0, sizeof(msg_simple));
        msg_simple.a = 10;
        strncpy(msg_simple.msg, "titi et rominet", MSG_MAX);
        msg_simple.msg[MSG_MAX - 1] = '\0';

        printf("%d => %s\n", msg_simple.a, msg_simple.msg);

        std::cout << "FIN" << std::endl;

        simple s;
        s.affiche();
        s.doudou = (void(*)(void*))&echo;
        s.doudou((char*)("titi et grosminet\n"));
        return 0;
}