#include <iostream>
#include <type_traits>
#include "include/binary.h"

int main() {
  std::cout << "1010: " << binary<1010>::value << std::endl;  
  std::cout << "1111: " << binary<1111>::value << std::endl;

  return 0;
}
