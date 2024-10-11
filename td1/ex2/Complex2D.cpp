#include "Complex2D.h"
#include <iostream>
#include <cmath>

Complex2D::Complex2D() : re(0.0), im(0.0){};
Complex2D::Complex2D(double _re, double _im) : re(_re), im(_im){};
Complex2D::Complex2D(double value) : re(value), im(value){};
Complex2D::Complex2D(Complex2D &c) : re(c.re), im(c.im){};
double Complex2D::getReal() {return re;}
double Complex2D::getImag() {return im;}
void Complex2D::setReal(double r) { re= r;}
void Complex2D::setImag(double i) { im = i;}
Complex2D Complex2D::operator+(Complex2D &c) {
    return Complex2D(re + c.re, im + c.im);
}
Complex2D Complex2D::operator-(Complex2D &c){
    return Complex2D(re - c.re, im - c.im);
}
Complex2D Complex2D::operator*(Complex2D &c){
    return Complex2D(
        re * c.re - im * c.im,
        re * c.im + im * c.re
    );
}
void Complex2D::print() const {
    std::cout << re << " + " << im << "i" << std::endl;
}
