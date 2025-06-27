#include <algorithm>
#include <vector>

# include "h.hpp"



int main()
{
    OurArray <ComplexNumber> arr(5);
    OurArray <ComplexNumber> arr2(5);

    arr[0] = {-1.1, 2};
    arr[1] = {0.1, 2};
    arr[2] = {1.1, 2};
    arr[3] = {2.1, 2};
    arr[4] = {3.1, 2};

    arr2[0] = arr[0] + ComplexNumber(-1.1, 1);
    arr2[1] = arr[1] + ComplexNumber(0.1, 1);
    arr2[2] = arr[2] + ComplexNumber(1.1, 1);
    arr2[3] = arr[3] + ComplexNumber(2.1, 1);
    arr2[4] = arr[4] + ComplexNumber(3.1, 1);

    arr += arr2;

    for (auto iter = arr.begin(); iter != arr.end(); ++iter)
        std::cout << *iter << std::endl;
    return 0;
}

