#ifndef D_H
#define D_H

#include "C.h"

class D : public C
{
public:
	virtual ~D() = default;
	virtual void pure() const noexcept = 0;
};

#endif
