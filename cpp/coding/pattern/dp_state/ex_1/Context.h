#ifndef _CONTEXT_H
#define _CONTEXT_H

class Element;
class ElementA;
class ElementB;

struct Context 
{
    ElementA *_elementA;
    ElementB *_elementB;
    Element *_element;
    unsigned int _nb_ite;

    Context(unsigned int);
    ~Context();

    void setElement(Element*);

    void transToA();
    void transToB();

    void infoState();
};

#endif // _CONTEXT_H
