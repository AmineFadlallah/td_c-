#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical();
    MatrixNumerical(size_t r, size_t c);

    T getDeterminant() const;
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> getInverse() const;
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other) const;

private:
    void getCofactor(const MatrixNumerical<T>& mat, MatrixNumerical<T>& temp, size_t p, size_t q, size_t n) const;
    T determinant(const MatrixNumerical<T>& mat, size_t n) const;
};

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>() {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}

template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    return determinant(*this, this->rows);
}

template <typename T>
T MatrixNumerical<T>::determinant(const MatrixNumerical<T>& mat, size_t n) const {
    if (n == 1)
        return mat.getElement(0, 0);

    T det = 0;
    MatrixNumerical<T> temp(mat.getRows(), mat.getCols());

    int sign = 1;

    for (size_t f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        det += sign * mat.getElement(0, f) * determinant(temp, n - 1);
        sign = -sign;
    }

    return det;
}

template <typename T>
void MatrixNumerical<T>::getCofactor(const MatrixNumerical<T>& mat, MatrixNumerical<T>& temp, size_t p, size_t q, size_t n) const {
    size_t i = 0, j = 0;
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp.addElement(i, j++, mat.getElement(row, col));
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) const {
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.addElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& other) const {
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.addElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& other) const {
    MatrixNumerical<T> result(this->rows, other.cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < other.cols; j++) {
            T sum = 0;
            for (size_t k = 0; k < this->cols; k++) {
                sum += this->getElement(i, k) * other.getElement(k, j);
            }
            result.addElement(i, j, sum);
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    T det = this->getDeterminant();
    if (det == 0)
        throw std::invalid_argument("Singular matrix, can't find its inverse");

    MatrixNumerical<T> adj(this->rows, this->cols);
    if (this->rows == 1) {
        adj.addElement(0, 0, 1);
        return adj;
    }

    int sign = 1;
    MatrixNumerical<T> temp(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            getCofactor(*this, temp, i, j, this->rows);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj.addElement(j, i, (sign) * (determinant(temp, this->rows - 1)));
        }
    }

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            adj.addElement(i, j, adj.getElement(i, j) / det);
        }
    }

    return adj;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& other) const {
    MatrixNumerical<T> inv = other.getInverse();
    return *this * inv;
}

#endif
