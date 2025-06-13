#include "h.hpp"

int main(void)
{
	A a;
	A b(10, 'b');
	A c(b);

	fun(b);
	std::cout << b.getX() << std::endl;
	a = b;
	a.show();
	return 0;
}
