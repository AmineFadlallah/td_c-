#include <iostream>
#include <string>
#include "Complex2D.h"

int main(){
	Complex2D c1;
	c1.print();
	Complex2D c2(3.5,4.6);
	c2.print();
	Complex2D c3(1.0);
	c3.print();
	Complex2D c4(c1);
	c4.print();
	std::cout << "Somme: "; (c2 + c3).print();
    	std::cout << "Différence: "; (c2 - c3).print();
    	std::cout << "Produit: "; (c2 * c3).print();

	return 0;
}
