# ifndef OURARRAY_HPP
# define OURARRAY_HPP

# include "h.hpp"

template <typename Type>
class OurArray
{
public:
    OurArray(){create();}
    OurArray(const OurArray &our_array)
    {
        capacity = our_array.capacity;
        size = our_array.size;
        arr = new Type[capacity];

        for (int i=0; i < size; i++)
            arr[i] = our_array.arr[i];
    }
    OurArray(std::size_t n)
    {
        capacity = 2*n;
        size = n;
        arr = new Type[capacity];
    }
    OurArray(std::size_t n, Type default_value)
    {
        capacity = 2*n;
        size = n;
        arr = new Type[capacity];

        for (std::size_t i=0; i<size; i++)
            arr[i] = default_value;
    }
    OurArray(OurArray &&other)
    {
        capacity = other.capacity;
        size = other.size;
        arr = other.arr;
        other.create();
    }
    ~OurArray(){delete[] arr;}

    OurArray<Type>& operator=(const OurArray &our_array)
    {
        capacity = our_array.capacity;
        size = our_array.size;
        arr = new Type[capacity];

        for (int i=0; i < size; i++)
            arr[i] = our_array.arr[i];
        return *this;
    }
    Type& operator[](std::size_t index)
    {
        return arr[index];
    }
    std::size_t size_arr() const
    {
        return size;
    }
    void resize(std::size_t new_capacity)
    {
        if (new_capacity==capacity)
            return;
        if (new_capacity < size)
            size = new_capacity;

        Type *new_arr = new Type[new_capacity];
        for (std::size_t i = 0; i<size; i++)
            new_arr[i] = arr[i];
        delete arr;
        arr = new_arr;

        capacity = new_capacity;
    }
    void push_back(Type value)
    {
        if (size == capacity)
            resize(capacity*2);
        arr[size] = value;
        size++;
    }
    void push_front(Type value)
    {
        if (size == capacity)
            resize(capacity*2);
        size++;
        Type next_el = arr[0];
        arr[0] = value;
        for (std::size_t i = 1; i<size+1; i++)
        {
            const Type next_el2 = arr[i];
            arr[i] = next_el;
            next_el = next_el2;
        }

    }
    Type pop_front()
    {
        if (size == 0)
            return -1; //?
        if (size*2 < capacity)
            resize(capacity/2);
        const Type res = arr[0];
        for (std::size_t i = 0; i<size; i++)
        {
            const Type next_el = arr[i+1];
            arr[i] = next_el;
        }
        size--;
        return res;
    }
    Type pop_back()
    {
        if (size == 0)
            return -1; //?
        if (size*2 < capacity)
            resize(capacity/2);
        const Type res = arr[size-1];
        size--;
        return res;
    }
    void sort_arr()
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
    void show() const
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
    void reverse_arr() const
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
                const Type switch_1 = arr[i];
                const Type switch_2 = arr[size-i-1];
                arr[i] = switch_2;
                arr[size-i-1] = switch_1;
            }
        }
    }

    std::size_t capacity_arr() const
    {
        return capacity;
    }

    void set_null() const
    {
        for (std::size_t i = 0; i<size; i++)
        {
            arr[i] = 0;
        }
    }
    void create()
    {
        capacity = DEFAULT_CAPACITY;
        size = 0;
        arr = new Type[capacity];
    }
    OurArray<Type> operator+=(const OurArray &our_array)
    {
        if (size == 0)
        {
            *this=our_array;
            return *this;
        }

        const std::size_t orig_size = size;
        size += our_array.size;

        if (size >= capacity)
            resize(size*2);


        for (std::size_t i=orig_size; i < size; i++)
            arr[i] = our_array.arr[i-orig_size];
        return *this;
    }

    class Iterator
    {
    public:
        Iterator(){index = 0; our_array = NULL;}
        Iterator(std::size_t n){index = n; our_array = NULL;}

        Iterator &operator=(Iterator iter){
            index = iter.index; 
            our_array = iter.our_array;
            return *this;
        }

        Type operator*(){return (*our_array)[index];}
        Iterator operator++(){index++; return *this;}
        bool operator==(Iterator iter){return index == iter.index;}
        bool operator!=(Iterator iter){return index != iter.index;}

        friend class OurArray<Type>;

    private:
        OurArray<Type> *our_array;
        std::size_t index;
    };

    Iterator begin(){
        Iterator iter;
        iter.our_array = this;
        return iter;
    }

    Iterator end()
    {
        Iterator iter(size);
        iter.our_array = this;
        return iter;
    }

private:
    Type *arr;
    std::size_t size;
    std::size_t capacity; // хранилище
};

# endif
