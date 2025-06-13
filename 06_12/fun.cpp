#include "h.hpp"

class A
{
public:
	A()
	{
		x = 0;
		c = 'a';
		std::cout << "Contructor: No arguments" << std::endl;
	}
	A(int x_, char c_)
	{
		x = x_;
		c = c_;
		std::cout << "Contructor: 2 arguments" << std::endl;
	}

	A(const A &a)
	{
		x = a.x;
		c = a.c;
		std::cout << "Contructor: Copy" << std::endl;
	}

	void show() const
	{
		std::cout << "A: x = " << x << ", c = " << c << std::endl;
	}

	void setX(int x_)
	{
		x = x_;
	}

	void setC(int c_)
	{
		c = c_;
	}

	int &getX()
	{
		if (x < 0)
			x = 0;
		return x;
	}

	char &getC()
	{
		return c;
	}

	friend void fun(A &a);

private:
	int		x;
	char	c;
};

void fun(A &a)
{
	a.x++;
}
