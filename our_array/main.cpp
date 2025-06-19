#include <algorithm>

# include "h.hpp"

int main()
{
    // test: show and creat
    OurArray our_array(5);

    for (std::size_t i=0; i<our_array.size_arr(); i++)
    {
        our_array[i] = i*i;
    }

    our_array.show();

    // test: sort_arr
    // OurArray shuffled_arr(6);
    // shuffled_arr[0] = 5;
    // shuffled_arr[1] = 3;
    // shuffled_arr[2] = 1;
    // shuffled_arr[3] = 2;
    // shuffled_arr[4] = 4;
    // shuffled_arr[5] = 0;

    // shuffled_arr.show();
    // shuffled_arr.sort_arr();
    // shuffled_arr.show();

    // test: sum
    OurArray our_array2(4);

    for (std::size_t i=0; i<our_array2.size_arr(); i++)
    {
        our_array2[i] = i+1;
    }

    our_array2+=our_array;
    our_array2.show();

    // test: push_back
    // for (std::size_t i=5; i<12; i++)
    // {
    //     our_array.push_back(i*i+1);
    // }

    // for (std::size_t i=0; i<our_array.size_arr(); i++)
    // {
    //     std::cout << our_array[i] << std::endl;
    // }
    return 0;
}

