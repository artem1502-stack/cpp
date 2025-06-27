#include "h.hpp"
#include "ComplexNumber.hpp"

int main()
{
    ComplexNumber num2(8, 9);
    ComplexNumber num3(3, 2);
    num3.show();
    num2.show();

    auto n3 = num2.conjugate();
    n3.show();

    return 0;
}
