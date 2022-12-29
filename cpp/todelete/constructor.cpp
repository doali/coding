#include <iostream>
#include <stdlib.h>
#include <vector>

#include <cstdio> // todelete
#include <cstring> // todelete

#define INFO std::cout << "func:" << __func__ << std::endl
#define INFO_ std::cout << "func:" << __func__
#define INFO_SZ 256
#define INFO_OBJ(OBJ) std::cout << OBJ << " " << __func__ << std::endl

static void byebye(); // todelete

struct A
{
    static u_int16_t _total;
    u_int16_t _id;
    A() : _id(_total)
    {
        ++_total;
        INFO_OBJ(*this);
    }

    A(A const &obj) : _id(obj._id)
    {                
        ++_total;
        INFO_OBJ(*this);
    }

    ~A()
    {
        --_total;
        INFO_OBJ(*this);
    }

    A &operator=(A const &other)
    {
        INFO_ << ", " << this->_id << " <- " << other._id << "---<<<" << std::endl;

        if (this == &other)
        {
            return *this;
        }

        INFO_ << ", " << this->_id << " <- " << other._id << "<<<---" << std::endl;

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &, A const &);
};

std::ostream &operator<<(std::ostream &os, A const &obj)
{
    char buffer[INFO_SZ];
    sprintf(buffer, "{%2u|%2u}", obj._id, A::_total);

    return os << buffer;
}

u_int16_t A::_total{0};

int main(int argc, char **argv)
{
    // A a_0;

    // A a_1();
    // a_1();

    // A a_2{};

    // A();
    // A{};

    // A a_3 = A();
    // A a_4;

    // a_4 = a_3;

    // A const &a_5 = A();

    // A a_6, a_7, a_8;        
    // A a_9 = a_7;

    // INFO;

    byebye();

    return EXIT_SUCCESS;
}

A a_1()
{
    INFO;

    return A();
}

static void byebye() // todelete
{
    std::string str {""};
    while (std::cin >> str)
    {
        std::cout << str << std::endl;

        if (str.compare("titi1") == 0) break;
    }

    char buf[INFO_SZ];
    memset(buf, 0, sizeof(buf));
    size_t sz_key = strlen("titi2");
    std::cout << "sz_key:" << sz_key << std::endl;
    while (true)
    {
        scanf("%s", buf);

        if (strcmp(buf, "titi2") == 0) break;
    }    
}