#include "Element.h"
#include "Context.h"
#include <iostream>

Element::Element(Context *ctx) : _ctx{ctx}
{        
    // std::cout << __func__ << std::endl;
}

Element::~Element() = default;

ElementA::ElementA(Context *ctx) : Element(ctx) 
{
    // std::cout << __func__ << std::endl;
}

ElementA::~ElementA() = default;

void ElementA::transToA()
{
    // leave me empty
}

void ElementA::transToB()
{
    if (_ctx != nullptr)
    {
        _ctx->setElement(_ctx->_elementB);
        // std::cout << "A -> B" << std::endl;
    }
}

void ElementA::say()
{
    std::cout << "PING" << std::endl;
}

void ElementA::info()
{
    std::cout << "A" << std::endl;
}

ElementB::ElementB(Context *ctx) : Element(ctx) 
{
    // std::cout << __func__ << std::endl;
}

ElementB::~ElementB() = default;

void ElementB::transToA()
{
    if (_ctx != nullptr)
    {
        _ctx->setElement(_ctx->_elementA);
        // std::cout << "B -> A" << std::endl;
    }
}

void ElementB::transToB()
{
    // leave me empty
}

void ElementB::say()
{
    std::cout << "PONG"  << std::endl;
}

void ElementB::info()
{
    std::cout << "B" << std::endl;
}
