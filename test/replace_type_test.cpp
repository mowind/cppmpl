#include <type_traits>
#include <iostream>
#include <vector>

#include "replace_type.h"

using std::cout;
using std::endl;

int main() {
  std::cout << std::boolalpha;
  std::cout << std::is_same<replace_type<int***, int, float>::type, float***>::value << std::endl;
  std::cout << std::is_same<replace_type<int[1][2][3], int, float>::type, float[1][2][3]>::value << std::endl;
  //int****& to float****&
	cout << std::is_same<replace_type<int****&, int, float>::type, float****&>::value << endl;
	//const int ****& to volatile float****&
	cout << std::is_same<replace_type<const int****&, const int, volatile float>::type, volatile float****&>::value << endl;
	//int**&() to double**&()
	cout << std::is_same<replace_type<int**&(), int, double>::type, double**&()>::value << endl;
	//int**&(int) to double**&(double)
	cout << std::is_same<replace_type<int**&(int), int, double>::type, double**&(double)>::value << endl;
	//int**&(int, int*, int[]) to double**&(double, double*, double[])
	cout << std::is_same<replace_type<int**&(int, int*, int[]), int, double>::type, double**&(double, double*, double[])>::value << endl;
	//int(*&)(int(*&)(int)) to double(*&)(double(*&)(double))
	cout << std::is_same<replace_type<int(*&)(int(*&)(int)), int, double>::type, double(*&)(double(*&)(double))>::value << endl;
	//const double*& to std::vector<int>*&
	cout << std::is_same<replace_type<const double*&, const double, std::vector<int>>::type, std::vector<int>*&>::value << endl;
    return 0;

  return 0;
}
