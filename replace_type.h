#include <type_traits>

template <class C, class X, class Y>
struct replace_type {
  using type = C;
};

template <class C, class Y>
struct replace_type<C, C, Y> {
  using type = Y;
};

template <class C, class Y>
struct replace_type<C*, C, Y> {
  using type = Y*;
};

template <class C, class Y>
struct replace_type<C&, C, Y> {
  using type = Y&;
};

template <class C, class Y, size_t N>
struct replace_type<C[N], C, Y> {
  using type = Y[N];
};

template <class C, class X, class Y>
struct replace_type<C*, X, Y> {
  using type = typename replace_type<C, X, Y>::type*;
};

template <class C, class X, class Y>
struct replace_type<C&, X, Y> {
  using type = typename replace_type<C, X, Y>::type&;
};

template <class C, class X, class Y, size_t N>
struct replace_type<C[N], X, Y> {
  using type = typename replace_type<C, X, Y>::type[N];
};

template <class R, class X, class Y>
struct replace_type<R(), X, Y> {
  using type = typename replace_type<R, X, Y>::type();
};

template <class R, class X, class Y, class ...Args>
struct replace_type<R(Args...), X, Y> {
  using type = 
      typename replace_type<R, X, Y>::type(
          typename replace_type<Args, X, Y>::type...);
};
