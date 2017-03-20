#include <iostream>

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/static_assert.hpp>

namespace mpl = boost::mpl;

using namespace mpl::placeholders;

namespace cppmpl {

typedef mpl::vector_c<int, 1, 0, 0, 0, 0, 0, 0> mass;
typedef mpl::vector_c<int, 0, 1, 0, 0, 0, 0, 0> length;    
typedef mpl::vector_c<int, 0, 0, 1, 0, 0, 0, 0> time;
typedef mpl::vector_c<int, 0, 0, 0, 1, 0, 0, 0> charge;
typedef mpl::vector_c<int, 0, 0, 0, 0, 1, 0, 0> temperature;
typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 1, 0> intensity;
typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 1> amount_of_substance;

typedef mpl::vector_c<int, 0, 1, -1, 0, 0, 0, 0> velocity;       // 1/t
typedef mpl::vector_c<int, 0, 1, -2, 0, 0, 0, 0> acceleration;   // 1/(t^2)
typedef mpl::vector_c<int, 1, 1, -1, 0, 0, 0, 0> mementum;       // ml/t
typedef mpl::vector_c<int, 1, 1, -2, 0, 0, 0, 0> force;          // ml/(t^2)
typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 0> scalar;

template <class T, class Dimesions>
struct quantity {
  explicit quantity(T x)
      : value_(x) { }

  // 转换构造器
  template <class OtherDimensions>
  quantity(quantity<T, OtherDimensions> const& rhs) 
      : value_(rhs.value()) {
    BOOST_STATIC_ASSERT((
      mpl::equal<Dimesions, OtherDimensions>::type::value
    ));
  }

  T value() const { return value_; }
 private:
  T value_;
};

template <class T, class D>
quantity<T, D>
operator+(quantity<T, D> x, quantity<T, D> y) {
  return quantity<T, D>(x.value() + y.value());
}

template <class T, class D>
quantity<T, D>
operator-(quantity<T, D> x, quantity<T, D> y) {
  return quantity<T, D>(x.value() - y.value());
}

struct plus_f {
  template <class T1, class T2>
  struct apply {
    typedef typename mpl::plus<T1, T2>::type type;
  };
};

template <class T, class D1, class D2>
quantity< T, typename mpl::transform<D1, D2, plus_f>::type>
operator*(quantity<T, D1> x, quantity<T, D2> y) {
  typedef typename mpl::transform<D1, D2, plus_f>::type dim;
  return quantity<T, dim>(x.value() * y.value());
}

/*
struct minus_f {
  template <class T1, class T2>
  struct apply : mpl::min<T1, T2> { };
};

template <class T, class D1, class D2>
quantity<T, typename mpl::transform<D1, D2, mpl::minus<_1, _2>>::type>
operator/(quantity<T, D1> x, quantity<T, D2> y) {
  typedef typename 
      mpl::transform<D1, D2, mpl::minus<_1, _2>>::type dim;
  return quantity<T, dim>(x.value() / y.value());
}
*/

template <class D1, class D2>
struct divide_dimensions
  : mpl::transform<D1, D2, mpl::minus<_1, _2>> { };

template <class T, class D1, class D2>
quantity<T, typename divide_dimensions<D1, D2>::type>
operator/(quantity<T, D1> x, quantity<T, D2> y) {
  return quantity<T, typename divide_dimensions<D1, D2>::type>(
      x.value() / y.value());
}

}  // namespace cppmpl
