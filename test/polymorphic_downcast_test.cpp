#include <iostream>
#include "polymorphic_downcast.h"

struct A { virtual ~A() {} };
struct B : public A { };

int main() {
  B b;
  A* a_ptr = &b;
  B* b_ptr = polymorphic_downcast<A*>(a_ptr);
}
