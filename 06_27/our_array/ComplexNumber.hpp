# ifndef COMPLEXNUMBER_HPP
# define COMPLEXNUMBER_HPP


class ComplexNumber
{
public:
    ComplexNumber();
    explicit ComplexNumber(double real_part);
    ComplexNumber(double real_part, double imaginary_part);
	ComplexNumber(const ComplexNumber &complex_number);

    // > < >= <= abs
	ComplexNumber& operator=(const ComplexNumber &complex_number);
    ComplexNumber& operator=(const double number);

    ComplexNumber& operator+=(const ComplexNumber &complex_number);
    ComplexNumber operator+(const ComplexNumber &complex_number) const; //this

    ComplexNumber& operator-=(const ComplexNumber &complex_number);
    ComplexNumber operator-(const ComplexNumber &complex_number) const;

    ComplexNumber& operator*=(const ComplexNumber &complex_number);
    ComplexNumber operator*(const ComplexNumber &complex_number) const;

    double absolute() const;

    bool operator==(const ComplexNumber&) const;
    bool is_equal_to(const ComplexNumber &complex_number) const;
    bool abs_equal_to(const ComplexNumber &complex_number) const;
    void show() const;
    ComplexNumber conjugate() const;

    friend std::ostream& operator<<(std::ostream &out, const ComplexNumber &cn);    

private:
    double real;
    double imaginary;
};

# endif
