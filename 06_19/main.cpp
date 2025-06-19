#include <iostream>


template <typename T>
T max(T a, T b)
{
	return (a >= b ? a : b);
}

int main(void)
{
	int a_int = 5, b_int = 7;
	double a_double = 3.2, b_double = 2.7;
	char a_char = 'a', b_char = 'b';

	std::cout << max<int>(a_int, b_int) << std::endl;
	std::cout << max<double>(a_double, b_double) << std::endl;
	std::cout << max<char>(a_char, b_char) << std::endl;
	return 0;
}
