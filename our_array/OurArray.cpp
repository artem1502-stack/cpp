# include "h.hpp"


OurArray::OurArray()
{
    capacity = DEFAULT_CAPACITY;
    size = 0;
    arr = new double[capacity];
}

OurArray::OurArray(const OurArray &our_array)
{
    capacity = our_array.capacity;
    size = our_array.size;
    arr = new double[capacity];

    for (int i=0; i < size; i++)
        arr[i] = our_array.arr[i];

}

OurArray::OurArray(std::size_t n)
{
    capacity = 2*n;
    size = n;
    arr = new double[capacity];

}


OurArray::OurArray(std::size_t n, double default_value)
{
    capacity = 2*n;
    size = n;
    arr = new double[capacity];

    for (std::size_t i=0; i<size; i++)
        arr[i] = default_value;
}


OurArray::~OurArray()
{
    delete arr;
    std::cout << "Deleted" << std::endl;
}

OurArray& OurArray::operator=(const OurArray &our_array)
{
    capacity = our_array.capacity;
    size = our_array.size;
    arr = new double[capacity];

    for (int i=0; i < size; i++)
        arr[i] = our_array.arr[i];
    return *this;
}

double& OurArray::operator[](std::size_t index)
{
    return arr[index];
}

std::size_t OurArray::size_arr() const
{
    return size;
}

void OurArray::resize(std::size_t new_capacity)
{
    if (new_capacity==capacity)
        return;
    if (new_capacity < size)
        size = new_capacity;

    double *new_arr = new double[new_capacity];
    for (std::size_t i = 0; i<size; i++)
        new_arr[i] = arr[i];
    delete arr;
    arr = new_arr;

    capacity = new_capacity;

}

void OurArray::push_back(double value)
{
    if (size == capacity)
        resize(capacity*2);
    arr[size] = value;
    size++;
}


void OurArray::push_front(double value)
{
    if (size == capacity)
        resize(capacity*2);
    size++;
    double next_el = arr[0];
    arr[0] = value;
    for (std::size_t i = 1; i<size+1; i++)
    {
        const double next_el2 = arr[i];
        arr[i] = next_el;
        next_el = next_el2;
    }

}

double OurArray::pop_front()
{
    if (size == 0)
        return -1; //?
    if (size*2 < capacity)
        resize(capacity/2);
    const double res = arr[0];
    for (std::size_t i = 0; i<size; i++)
    {
        const double next_el = arr[i+1];
        arr[i] = next_el;
    }
    size--;
    return res;
}

double OurArray::pop_back()
{
    if (size == 0)
        return -1; //?
    if (size*2 < capacity)
        resize(capacity/2);
    const double res = arr[size-1];
    size--;
    return res;
}


void OurArray::sort_arr() // comb sort
// not the most efficient
{
    if (size == 0)
        return;

    const float DECLINE_STEP = 1.247;

    std::size_t step = size /  DECLINE_STEP;
    std::cout << step << std::endl;
    while (step >= 1)
    {
        for (std::size_t i=0; i<size-step+1; i++)
        {
            if (arr[step+i] < arr[i])
                std::swap(arr[step+i], arr[i]);
        }
        step = step / DECLINE_STEP;
    }


}


void OurArray::show() const
{
    if (size == 0)
        std::cout << "Empty array!" << std::endl;
    else
    {
        for (std::size_t i = 0; i<size-1; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << arr[size-1] << ";" << std::endl;
    }
}


void OurArray::reverse_arr() const
{
    if (size == 0)
        std::cout << "Empty array!" << std::endl;
    else
    {
        std::size_t stop = size/2;
        if (size % 2 != 0)
            stop++;

        for (std::size_t i = 0; i<stop; i++)
        {
            const double switch_1 = arr[i];
            const double switch_2 = arr[size-i-1];
            arr[i] = switch_2;
            arr[size-i-1] = switch_1;
        }
    }
}

std::size_t OurArray::capacity_arr() const
{
    return capacity;
}

void OurArray:: set_null() const
{
    for (std::size_t i = 0; i<size; i++)
    {
        arr[i] = 0;
    }
}


void OurArray::operator+=(const OurArray &our_array)
{
    if (size == 0)
    {
        *this=our_array;
        return;
    }

    const std::size_t orig_size = size;
    size += our_array.size;

    if (size >= capacity)
        resize(capacity*2);


    for (std::size_t i=orig_size; i < size; i++)
        arr[i] = our_array.arr[i-orig_size];
}

