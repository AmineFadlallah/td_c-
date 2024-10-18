#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H
#include <vector>
#include <iostream>
template <typename T>
class MatrixBase{
	protected:
		std::vector<std::vector<T>> data;
		size_t rows;
		size_t cols;
	public:
		MatrixBase();
		MatrixBase(size_t r,size_t c);
		void addElement(size_t i, size_t j, T value);
		T getElement(size_t i, size_t j) const;
		size_t getRows() const;
		size_t getCols() const;
		void Display() const;
};

template <typename T>
MatrixBase<T>::MatrixBase() : data(1, std::vector<T>(1, 0)), rows(1), cols(1) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c) : rows(r), cols(c) {
    data.resize(r, std::vector<T>(c, 0));  // Initialize matrix with zeros
}

template <typename T>
void MatrixBase<T>::addElement(size_t i, size_t j, T value) {
    if (i < rows && j < cols)
        data[i][j] = value;
    else
        throw std::out_of_range("Index out of range");
}

template <typename T>
T MatrixBase<T>::getElement(size_t i, size_t j) const {
    if (i < rows && j < cols)
        return data[i][j];
    else
        throw std::out_of_range("Index out of range");
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}

template <typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif
