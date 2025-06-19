#include <algorithm>
#include <vector>

# include "h.hpp"

int main()
{
    OurArray arr(5);

    arr[0] = -1;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 3;

    OurArray::Iterator iter;
    for (iter = arr.begin(); iter != arr.end(); ++iter)
        std::cout << *iter << std::endl;
    return 0;
}

