#include "h.hpp"

A::A()
{
	x = 0;
	c = 'a';
	std::cout << "Contructor: No arguments" << std::endl;
}

A::A(int x_, char c_)
{
	x = x_;
	c = c_;
	std::cout << "Contructor: 2 arguments" << std::endl;
}

A::A(const A &a)
{
	x = a.x;
	c = a.c;
	std::cout << "Contructor: Copy" << std::endl;
}

A::~A()
{
	std::cout << "Destructor activated:" << std::endl;
	this->show();
}

A &A::operator=(const A &a)
{
	x = a.x;
	c = a.c;
	return *this;
}

void A::show() const
{
	std::cout << "A: x = " << x << ", c = " << c << std::endl;
}

void A::setX(int x_)
{
	x = x_;
}

void A::setC(int c_)
{
	c = c_;
}

int &A::getX()
{
	if (x < 0)
		x = 0;
	return x;
}

char &A::getC()
{
	return c;
}

void fun(A &a)
{
	a.x++;
}
