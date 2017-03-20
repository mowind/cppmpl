#include <iostream>
#include <typeinfo>
#include "add_const_ref.h"

struct type { }; 

int main() {
  std::cout << "type: " << std::boolalpha 
            << std::is_same<type&, add_const_ref<type&>::type>::value 
            << std::endl;
  std::cout << "const type&: " << std::boolalpha 
            << std::is_same<const type&, add_const_ref<type>::type>::value 
            << std::endl;

  return 0;
}
