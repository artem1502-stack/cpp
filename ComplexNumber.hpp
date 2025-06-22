# ifndef COMPLEXNUMBER_HPP
# define COMPLEXNUMBER_HPP


class ComplexNumber
{
public:
    ComplexNumber();
    ComplexNumber(double imaginary_part);
    ComplexNumber(double real_part, double imaginary_part);
    // ~ComplexNumber();

    void show() const;
    void absolute() const;
    void conjugate();
    void operator+=(const ComplexNumber &complex_number);
    void operator-=(const ComplexNumber &complex_number);
    void operator*=(const ComplexNumber &complex_number);
    bool is_equal_to(const ComplexNumber &complex_number) const;
    bool abs_equal_to(const ComplexNumber &complex_number) const;


private:
    double real;
    double imaginary;
};


# endif
