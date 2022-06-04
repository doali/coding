#include <iostream>

struct ElementA;
struct ElementB;
struct Element;

struct Context 
{
    ElementA *_elementA;
    ElementB *_elementB;
    Element *_element;
    unsigned int _nb_ite;

    Context(unsigned int);
    ~Context();

    void setElement(Element*);

    void shiftToA();
    void shiftToB();

    void infoState();
};

struct Element 
{    
    Context *_ctx;
    
    Element(Context *ctx) : _ctx{ctx}
    {        
        // std::cout << __func__ << std::endl;
    }
    virtual ~Element() = 0;

    virtual void transToA() = 0;
    virtual void transToB() = 0;

    virtual void say() = 0;
    virtual void info() = 0;
};

Element::~Element() = default;

struct ElementA : Element
{
    ElementA(Context *ctx) : Element(ctx) 
    {
        // std::cout << __func__ << std::endl;
    }

    ~ElementA() override = default;

    void transToA() override
    {
        // leave me empty
    }

    void transToB() override;

    void say() override
    {
        std::cout << "PING" << std::endl;
    }

    void info() override
    {
        std::cout << "A" << std::endl;
    }
};

struct ElementB : Element
{
    ElementB(Context *ctx) : Element(ctx) 
    {
        // std::cout << __func__ << std::endl;
    }
    ~ElementB() override = default;

    void transToA() override
    {
        if (_ctx != nullptr)
        {
            _ctx->setElement(_ctx->_elementA);
            // std::cout << "B -> A" << std::endl;
        }        
    }

    void transToB() override
    {
        // leave me empty
    }

    void say() override
    {
        std::cout << "PONG"  << std::endl;
    }

    void info() override
    {
        std::cout << "B" << std::endl;
    }
};

void ElementA::transToB()
{
    if (_ctx != nullptr)
    {
        _ctx->setElement(_ctx->_elementB);
        // std::cout << "A -> B" << std::endl;
    }
}    

Context::Context(unsigned int nb_ite) :
    _nb_ite{nb_ite}
{
    _elementA = new ElementA(this);
    _elementB = new ElementB(this);
    _element = _elementA; // initial state
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

void Context::shiftToA() 
{
    _element->transToA();
}

void Context::shiftToB()
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
        ctx.shiftToA();
        ctx.infoState();

        ctx.shiftToB();
        ctx.infoState();

        --ctx._nb_ite;
    }
    
    return 0;
}