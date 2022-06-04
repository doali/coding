#ifndef _ELEMENT_H
#define _ELEMENT_H

struct Context;

struct Element 
{    
    Context *_ctx;

    Element(Context*);
    virtual ~Element() = 0;

    virtual void transToA() = 0;
    virtual void transToB() = 0;

    virtual void say() = 0;
    virtual void info() = 0;
};

struct ElementA : Element
{
    ElementA(Context*);
    ~ElementA() override;

    void transToA() override;
    void transToB() override;

    void say() override;
    void info() override;
};

struct ElementB : Element
{
    ElementB(Context*);
    ~ElementB() override;

    void transToA() override;
    void transToB() override;

    void say() override;
    void info() override;
};

#endif // _ELEMENT_H