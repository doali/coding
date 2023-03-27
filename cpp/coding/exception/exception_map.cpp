#include <iostream>
#include <functional>
#include <map>
#include <exception>

namespace
{
    struct DivisionZero : public std::exception
    {
        DivisionZero(int a) : std::exception{}, _a{a} {}
        const char *what() const noexcept override
        {
            static std::string msg{}; // static keyword is important !!
            msg = std::to_string(_a) + " can not be divided by zero";
            return msg.c_str();
        }
        int _a;
    };

    struct Calculator
    {
        enum class OPERATION
        {
            ADD,
            SUB,
            MUL,
            DIV
        };

        static int add(int a, int b) { return a + b; }
        static int sub(int a, int b) { return a - b; }
        static int mul(int a, int b) { return a * b; }

        static int div(int a, int b)
        {
            if (b == 0)
                throw DivisionZero(a);
            else
                return a / b;
        }

        static std::map<Calculator::OPERATION, std::function<int(int, int)>> compute;
    };

    std::map<Calculator::OPERATION, std::function<int(int, int)>> Calculator::compute{
        {OPERATION::ADD, Calculator::add},
        {OPERATION::SUB, Calculator::sub},
        {OPERATION::MUL, Calculator::mul},
        {OPERATION::DIV, Calculator::div}};
}

int main(int argc, char **argv)
{
    std::function<int(int, int)> add = Calculator::add;
    int res{0};
    res = add(40, 2);
    std::cout << res << std::endl;

    res = Calculator::compute[Calculator::OPERATION::ADD](40, 2);
    std::cout << res << std::endl;

    res = Calculator::compute[Calculator::OPERATION::SUB](44, 2);
    std::cout << res << std::endl;

    res = Calculator::compute[Calculator::OPERATION::MUL](21, 2);
    std::cout << res << std::endl;

    res = Calculator::compute[Calculator::OPERATION::DIV](84, 2);
    std::cout << res << std::endl;

    try
    {
        try
        {
            res = Calculator::compute[Calculator::OPERATION::DIV](84, 0);
            std::cout << res << std::endl;
        }
        catch (DivisionZero &e)
        {
            std::cout << e.what() << std::endl;

            res = Calculator::compute[Calculator::OPERATION::DIV](48, 0);
            std::cout << res << std::endl;
        }
    }
    catch (DivisionZero &f)
    {
        std::cout << f.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Something bad happened" << std::endl;
    }

    return EXIT_SUCCESS;
}