#include <iostream>

#include "type_descriptor.h"

int main() {
  std::cout << type_descriptor<char>() << std::endl;
  std::cout << type_descriptor<int>() << std::endl;
  std::cout << type_descriptor<short int>() << std::endl;
  std::cout << type_descriptor<long int>() << std::endl;

  std::cout << type_descriptor<char*>() << std::endl;
  std::cout << type_descriptor<int*>() << std::endl;
  std::cout << type_descriptor<short int*>() << std::endl;
  std::cout << type_descriptor<long int*>() << std::endl;

  std::cout << type_descriptor<char&>() << std::endl;
  std::cout << type_descriptor<int&>() << std::endl;
  std::cout << type_descriptor<short int&>() << std::endl;
  std::cout << type_descriptor<long int&>() << std::endl;
  return 0;
}
