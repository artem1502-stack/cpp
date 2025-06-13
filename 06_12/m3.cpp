#include "h.hpp"

#include <vector>
#include <algorithm>

#define N 10


std::ostream &operator<<(std::ostream &out, std::vector<int> x)
{
	for (int i = 0; i < x.size(); i++)
		out << x[i] << " ";
	return out;
}

bool compare(int a, int b)
{
	return abs(a) < abs(b);
}

int main(void)
{
	std::vector <int> x(N);

	for (int i = 0; i < x.size(); i++)
		x[i] = 4 * i * i - i * i * i - 4 * i;

	x.push_back(1111);

	std::sort(x.begin(), x.end());
	std::cout << x << std::endl;
	std::sort(x.begin(), x.end(), compare);
	std::cout << x << std::endl;

}
