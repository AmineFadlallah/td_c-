#include <iostream>
#include <string>
#include"my_class.h"

//question 2
//#include "printmessage.h"
/*void fct_imprime(std::string input){
	std::cout << input << std::endl;
}*/

int main() {
	//std::cout << "Hello World" << std::endl;
	//fct_imprime("Hello World");
	
	
	//printmessage("Hello World");
	
	my_class c;
	c.print_my_element();

	my_class c1("Hello World");
	c1.print_my_element();

	return 0;
}

