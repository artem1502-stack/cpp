# ifndef OURARRAY_HPP
# define OURARRAY_HPP
# include "h.hpp"

class OurArray
{
public:
    OurArray();
    OurArray(const OurArray &our_array);
    OurArray(std::size_t n);
    OurArray(std::size_t n, double default_value);
    ~OurArray();

    OurArray& operator=(const OurArray &our_array);
    double& operator[](std::size_t index);
    std::size_t size_arr() const;
    void resize(std::size_t capacity);
    void push_back(double value);

    void push_front(double value);
    double pop_front();
    double pop_back();
    void sort_arr();
    void show() const;
    void reverse_arr() const;
    std::size_t capacity_arr() const;
    void set_null() const;
    void operator+=(const OurArray &our_array); // OurArray&?

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

        double operator*(){return (*our_array)[index];}
        Iterator operator++(){index++; return *this;}
        bool operator==(Iterator iter){return index == iter.index;}
        bool operator!=(Iterator iter){return index != iter.index;}

        friend class OurArray;

    private:
        OurArray *our_array;
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
    double *arr;
    std::size_t size;
    std::size_t capacity; // хранилище
};

# define DEFAULT_CAPACITY 10


# endif
