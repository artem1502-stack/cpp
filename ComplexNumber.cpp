#include "../h.hpp"


ComplexNumber::ComplexNumber()
{
    real = 0;
    imaginary = 1;

}

ComplexNumber::ComplexNumber(double real_part, double imaginary_part)
{
    real = real_part;
    imaginary = imaginary_part;

}

ComplexNumber::ComplexNumber(double imaginary_part)
{
    real = 0;
    imaginary = imaginary_part;
}

// ComplexNumber::~ComplexNumber()
// {
//
// }

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


void ComplexNumber::absolute() const
{
    std::cout << std::sqrt(real*real+imaginary*imaginary) << std::endl;
}

void ComplexNumber::conjugate()
{
    imaginary*=-1;
    show();
    imaginary*=-1;
}

void ComplexNumber::operator+=(const ComplexNumber& complex_number)
{
    real+=complex_number.real;
    imaginary+=complex_number.imaginary;
}

void ComplexNumber::operator-=(const ComplexNumber &complex_number)
{
    real-=complex_number.real;
    imaginary-=complex_number.imaginary;
}


void ComplexNumber::operator*=(const ComplexNumber &complex_number)
{
    const auto orig_real = real;
    real = real*complex_number.real + imaginary*complex_number.imaginary*(-1);
    imaginary = orig_real*complex_number.imaginary + imaginary*complex_number.real;
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


