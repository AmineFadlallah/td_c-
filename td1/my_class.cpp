#include <iostream>
#include <string>
#include "my_class.h"

my_class::my_class() : element("message par defaut"){}
my_class::my_class(std::string str) : element(str) {}

void my_class::print_my_element() {
	std::cout << element << std::endl;
}
