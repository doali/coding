#ifndef A_H
#define A_H

class A
{
public:
	virtual ~A() = default;
	virtual void do_something() const noexcept;
};

#endif
