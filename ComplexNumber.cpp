#include "h.hpp"


ComplexNumber::ComplexNumber()
{
    real = 0;
    imaginary = 0;

}

ComplexNumber::ComplexNumber(double real_part)
{
    real = real_part;
    imaginary = 0;
}

ComplexNumber::ComplexNumber(double real_part, double imaginary_part)
{
    real = real_part;
    imaginary = imaginary_part;

}

ComplexNumber::ComplexNumber(const ComplexNumber &complex_number)
{
    real = complex_number.real;
    imaginary = complex_number.imaginary;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& complex_number)
= default;

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& complex_number)
{
    real+=complex_number.real;
    imaginary+=complex_number.imaginary;
    return *this;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& complex_number) const
{
    return {real+complex_number.real, imaginary+complex_number.imaginary};
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber &complex_number)
{
    real-=complex_number.real;
    imaginary-=complex_number.imaginary;
    return *this;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& complex_number) const
{
    return {real-complex_number.real, imaginary-complex_number.imaginary};
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber &complex_number)
{
    const auto orig_real = real;
    real = real*complex_number.real + imaginary*complex_number.imaginary*(-1);
    imaginary = orig_real*complex_number.imaginary + imaginary*complex_number.real;
    return *this;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& complex_number) const
{
    const auto orig_real = real;
    return {real*complex_number.real + imaginary*complex_number.imaginary*(-1),
        orig_real*complex_number.imaginary + imaginary*complex_number.real};
}

bool ComplexNumber::operator==(const ComplexNumber& complex_number) const
{
    if (real == complex_number.real and imaginary == complex_number.imaginary)
        return true;
    return false;

}

bool ComplexNumber::is_equal_to(const ComplexNumber &complex_number) const
{
    if (real == complex_number.real and imaginary == complex_number.imaginary)
        return true;
    return false;
}

bool ComplexNumber::abs_equal_to(const ComplexNumber &complex_number) const
{
    if ((real == complex_number.real or real == -complex_number.real)
        and (imaginary == complex_number.imaginary or imaginary == -complex_number.imaginary))
        return true;
    return false;
}

void ComplexNumber::absolute() const
{
    std::cout << std::sqrt(real*real+imaginary*imaginary) << std::endl;
}

void ComplexNumber::show() const
{
    char operation;
    double show_imaginary = imaginary;

    if (imaginary == 0)
    {
        std::cout << real << std::endl;
        return;
    }

    if (real == 0)
    {
        if (imaginary == 1)
        {
            std::cout << 'i' << std::endl;
            return;
        }
        if (imaginary == -1)
        {
            std::cout << '-' << 'i' << std::endl;
            return;
        }
        std::cout << show_imaginary << 'i' << std::endl;
        return;
    }

    if (imaginary > 0)
        operation = '+';
    else
    {
        operation = '-';
        show_imaginary*=-1;
    }

    if (imaginary == 1 or imaginary == -1)
    {
        std::cout << real << " " << operation << " " << 'i' << std::endl;
        return;
    }

    std::cout << real << " " << operation << " " << show_imaginary << 'i' << std::endl;
}

ComplexNumber ComplexNumber::conjugate() const // returns a new complex number
{
    return {real, imaginary*-1};
}
