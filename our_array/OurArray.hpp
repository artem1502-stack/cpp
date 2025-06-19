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

    // push_front (сдвинуть все элементы) +
    // pop_front (возвращает значение) +
    // pop_back (возвращает значение) +
    // reverse +
    // сделать метод вывода +
    // сделать сортировку
    // доп конструктор с дефолтными элементами (size, каждый элемент по дефолту 1) -+
    // оператор суммы (складывать массивы) +
    // метод на получения capacity +
    // зануление (все элементы в рамках capacity (aka в хранилище) занулить +


private:
    double *arr;
    std::size_t size;
    std::size_t capacity; // хранилище
};

# define DEFAULT_CAPACITY 10


# endif
