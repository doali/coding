#include "Context.h"
#include "Element.h"
#include <iostream>

Context::Context(unsigned int nb_ite) :
    _nb_ite{nb_ite}
{
    _elementA = new ElementA(this);
    _elementB = new ElementB(this);
    _element = _elementA;
}

Context::~Context()
{
    delete _elementA;
    delete _elementB;
}

void Context::setElement(Element *element)
{
    _element = element;
}

void Context::transToA() 
{
    _element->transToA();
}

void Context::transToB()
{
    _element->transToB();
}

void Context::infoState()
{
    // _element->info();
    _element->say();
}

int main(int argc, char **argv)
{
    Context ctx{4};

    while (ctx._nb_ite != 0) 
    {
        ctx.transToA();
        ctx.infoState();

        ctx.transToB();
        ctx.infoState();

        --ctx._nb_ite;
    }
    
    return 0;
}