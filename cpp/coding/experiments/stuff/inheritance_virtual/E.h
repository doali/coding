#ifndef E_H
#define E_H

#include "D.h"

class E : public D
{
public:
	virtual ~E() = default;
	void pure() const noexcept override;
};

#endif
