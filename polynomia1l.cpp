#include <stdio.h>
#include "Polynomial.h"
int main() {
    printf("Nhap da thuc thu nhat:\n");
    Polynomial poly1 = inputPolynomial();

    printf("Nhap da thuc thu hai:\n");
    Polynomial poly2 = inputPolynomial();

    printf("Da thuc thu nhat: ");
    printPolynomial(poly1);
    printf("Da thuc thu hai: ");
    printPolynomial(poly2);

    Polynomial sum = add(poly1, poly2);
    printf("Tong: ");
    printPolynomial(sum);

    Polynomial derivative = derivate(poly1);
    printf("Dao ham da thuc thu nhat: ");
    printPolynomial(derivative);

    return 0;
}
