#include <type_traits>

template <class T, bool>
struct ref_type_impl;

template <class T>
struct add_const_ref {
  static bool const is_ref = std::is_reference<T>::value;

  typedef typename ref_type_impl<T, is_ref>::type type;
};

template <class T>
struct ref_type_impl<T, false> {
  typedef const T& type;
};

template <class T>
struct ref_type_impl<T, true> {
  typedef T type;
};
