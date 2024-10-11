#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
	private:
		double re;
		double im;
	public:
		Complex2D();
		Complex2D(double _re, double _im);
		Complex2D(double value);
		Complex2D(Complex2D &c);
		void print() const;
	        Complex2D operator+(Complex2D &c);
		Complex2D operator-(Complex2D &c);
		Complex2D operator*(Complex2D &c);
		double getReal();
                double getImag();
                void setReal(double r);
                void setImag(double i);
};

#endif
