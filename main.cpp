#include "h.hpp"
#include "ComplexNumber.hpp"

int main()
{
    ComplexNumber num(4, 3);
    num.show();

    ComplexNumber num2(5, -1);
    num2.show();

    num*=num2;
    num.show();

    return 0;
}
