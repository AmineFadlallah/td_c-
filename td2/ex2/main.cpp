#include "MatrixNumerical.h"
#include <iostream>

int main() {
    MatrixNumerical<double> mat1(2, 2);
    MatrixNumerical<double> mat2(2, 2);

    mat1.addElement(0, 0, 1.0);
    mat1.addElement(0, 1, 2.0);
    mat1.addElement(1, 0, 3.0);
    mat1.addElement(1, 1, 4.0);

    mat2.addElement(0, 0, 5.0);
    mat2.addElement(0, 1, 6.0);
    mat2.addElement(1, 0, 7.0);
    mat2.addElement(1, 1, 8.0);

    std::cout << "Matrix 1:" << std::endl;
    mat1.Display();
    std::cout << "Matrix 2:" << std::endl;
    mat2.Display();

    MatrixNumerical<double> sum = mat1 + mat2;
    std::cout << "Sum of mat1 and mat2:" << std::endl;
    sum.Display();

    MatrixNumerical<double> diff = mat1 - mat2;
    std::cout << "Difference of mat1 and mat2:" << std::endl;
    diff.Display();

    MatrixNumerical<double> prod = mat1 * mat2;
    std::cout << "Product of mat1 and mat2:" << std::endl;
    prod.Display();

    double det1 = mat1.getDeterminant();
    std::cout << "Determinant of mat1: " << det1 << std::endl;

    try {
        MatrixNumerical<double> inv = mat1.getInverse();
        std::cout << "Inverse of mat1:" << std::endl;
        inv.Display();
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
