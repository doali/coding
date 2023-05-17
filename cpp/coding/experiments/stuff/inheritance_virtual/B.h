#ifndef B_H
#define B_H

#include "A.h"

class B : public A
{
public:
	virtual ~B() = default;
	void do_something() const noexcept override;
};

#endif
