#include "h.hpp"

#define N 10

int main(void)
{
	int *x;

	x = new int[N];


	for (int i = 0; i < N; i++)
		x[i] = i * i;

	for (int i = 0; i < N; i++)
		std::cout << "x[" << i << "] = " << x[i] << std::endl;

	delete x;

	return 0;
}
