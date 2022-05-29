#include <iostream>
#include <vector>

class ElementA;
class ElementB;

struct Visitor
{
	Visitor() = default; 	
	virtual ~Visitor() = 0;
	virtual void visitElementA(ElementA*) const = 0;
	virtual void visitElementB(ElementB*) const = 0;
};

Visitor::~Visitor() = default;

struct Element
{
	Element() = default;
	virtual ~Element() = 0;	
	virtual void accept(Visitor*) = 0;
};

Element::~Element() = default;

struct ElementA : Element
{
	ElementA(): _des("element A") {}
	~ElementA() override = default;
	void display() { std::cout << _des << std::endl; }	
	void accept(Visitor *v) override { v->visitElementA(this); }	

	std::string _des;
};

struct ElementB : Element
{
	ElementB(): _des{2} {}
	~ElementB() override = default;
	void display() { std::cout << _des << std::endl; }	
	void accept(Visitor *v) override { v->visitElementB(this); }	

	int _des;
};

struct VisitorA : Visitor
{
	VisitorA() = default;
	~VisitorA() override = default;

	void visitElementA(ElementA *a) const override
	{
		std::cout << "A visits" << " [" << a << "] " << a->_des << std::endl;
	}

	void visitElementB(ElementB *b) const override
	{
		std::cout << "A visits" << " [" << b << "] element " << b->_des << std::endl;
	}
};

struct VisitorB : Visitor
{
	VisitorB() = default;
	~VisitorB() override = default;

	void visitElementA(ElementA *a) const override
	{
		std::cout << "B visits" << " [" << a << "] " << a->_des << std::endl;
	}

	void visitElementB(ElementB *b) const override
	{
		std::cout << "B visits" << " [" << b << "] element " << b->_des << std::endl;
	}
};

int main(int argc, char** argv)
{
	VisitorA vA;
	VisitorB vB;

	ElementA eA;
	ElementB eB;

	std::vector<Element*> vElmnt{
		&eA,
		&eB
	};

	for (auto elmnt : vElmnt) elmnt->accept(&vA);
	for (auto elmnt : vElmnt) elmnt->accept(&vB);

	return 0;
}
