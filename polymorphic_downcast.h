#include <type_traits>
#include <assert.h>

template <class Source>
struct polymorphic_downcast;

template <class Source>
struct polymorphic_downcast<Source*> {
  template <class Target>
  Target operator()(Source* x) {
    assert(dynamic_cast<Target>(x) == x);
    return static_cast<Target>(x);
  }
};

template <class Source>
struct polymorphic_downcast<Source&> {
  template <class Target>
  Target operator()(Source& x) {
    assert(dynamic_cast<Target>(x) == x);
    return static_cast<Target>(x);
  }
};
