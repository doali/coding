#include <iostream>

#define WOUT(A) std::cout << __LINE__ << "|" << #A << "|" << &A << "|" << A << std::endl
#define WOBJOUT(A) std::cout << __LINE__ << "|" << #A << "|" << &A << "|" << A.info() << std::endl

struct A
{
    std::string info()
    {
        return __func__;
    }

    // A& operator=(A const&) = delete; // uncomment implies error at compile time
};

struct B
{
    // B& operator=(B const&) = delete; // uncomment implies error at compile time
};

struct C : A, B
{

};

int main(int argc, char** argv)
{     
    int l_a0{0}; WOUT(l_a0);
    int l_a1{1}; WOUT(l_a1);

    int& r_a0{l_a0}; WOUT(r_a0);
    int& r_a1{l_a1}; WOUT(r_a1);

    r_a0 = 10;

    WOUT(l_a0);
    WOUT(r_a0);

    r_a0 = r_a1;

    WOUT(r_a0);
    WOUT(r_a1);

    const int& r_a2 = 3; WOUT(r_a2);

    const int& r_a3{r_a0}; WOUT(r_a3);
    
    WOUT(r_a0);

    int l_a4{4}; WOUT(l_a4);
    int l_a5{5}; WOUT(l_a5);

    int& r_a4{l_a4}; WOUT(r_a4);

    r_a4 = l_a5;
    WOUT(r_a4);
    WOUT(l_a5);

    C l_obj0; WOBJOUT(l_obj0);

    C& r_obj0{l_obj0}; WOBJOUT(r_obj0);

    C l_obj1; WOBJOUT(l_obj1);

    r_obj0 = l_obj1;
    WOBJOUT(r_obj0);

    int l_b0{100}; WOUT(l_b0);
    int l_b1{101}; WOUT(l_b1);

    int& r_b0{l_b0}; WOUT(r_b0);

    r_b0 = l_b1;
    WOUT(r_b0);
    WOUT(l_b0);
    WOUT(l_b1);

    return 0;
}