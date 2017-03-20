#include "quantity.h"

int main() {
  cppmpl::quantity<float, cppmpl::length> l(1.0f);
  cppmpl::quantity<float, cppmpl::mass> m(2.0f);

  cppmpl::quantity<float, cppmpl::length> len1(1.0f);
  cppmpl::quantity<float, cppmpl::length> len2(2.0f);
  std::cout << "plus: " << (len1 + len2).value() << std::endl;
  std::cout << "minus: " << (len1 - len2).value() << std::endl;

  cppmpl::quantity<float, cppmpl::acceleration> a(9.8f);
  std::cout << "multiplication: " << (a * m).value() << std::endl;

  cppmpl::quantity<float, cppmpl::force> f(9.0f);
  cppmpl::quantity<float, cppmpl::mass> m2 = f / a;
  std::cout << "div: " << m2.value() << std::endl;
  return 0;
}
