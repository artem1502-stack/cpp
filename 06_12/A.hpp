#ifndef A_HPP
#define A_HPP

#include "h.hpp"

class A
{
public:
	A();
	A(int x_, char c_);
	A(const A &a);
	~A();

	A &operator=(const A &a);


	void	show() const;
	void	setX(int x_);
	void	setC(int c_);
	int		&getX();
	char	&getC();
	
	friend	void fun(A &a);

private:
	int		x;
	char	c;
};

void	fun(A &a);

#endif
