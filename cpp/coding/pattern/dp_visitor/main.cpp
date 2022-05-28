#include <iostream>
#include <vector>

class Visitor;

struct Element
{
	Element() = default;
	virtual ~Element() = 0;	
	virtual void accept(Visitor*) = 0;
};

Element::~Element() = default;

struct Visitor
{
	Visitor() = default; 	
	virtual ~Visitor() = 0;
	virtual void visit(Element*) = 0;
};

Visitor::~Visitor() = default;

struct ElementA : Element
{
	ElementA(): _des("element A") {}
	~ElementA() override = default;
	void display() { std::cout << _des << std::endl; }	
	void accept(Visitor *v) override { v->visit(this); }	

	std::string _des;
};

struct ElementB : Element
{
	ElementB(): _des{"element B"} {}
	~ElementB() override = default;
	void display() { std::cout << _des << std::endl; }	
	void accept(Visitor *v) override { v->visit(this); }	

	std::string _des;
};

struct VisitorA : Visitor
{
	VisitorA() = default;
	~VisitorA() override = default;

	void visit(Element *a) override
	{
		std::cout << "A visits" << " " << static_cast<ElementA*>(a)->_des << std::endl;
	}
};

struct VisitorB : Visitor
{
	VisitorB() = default;
	~VisitorB() override = default;

	void visit(Element *b) override
	{
		std::cout << "B visits " << " " << static_cast<ElementB*>(b)->_des << std::endl;
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
}
