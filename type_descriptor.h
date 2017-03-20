#include <type_traits>

template <class T>
struct type_descriptor;

template <>
struct type_descriptor<char> {
  constexpr static const char* value = "char";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<int> {
  constexpr static const char* value = "int";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<short int> {
  constexpr static const char* value = "short int";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<long int> {
  constexpr static const char* value = "long int";
  constexpr operator const char*() const {
    return value;
  }
};

// pointer
template <>
struct type_descriptor<char*> {
  constexpr static const char* value = "char*";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<int*> {
  constexpr static const char* value = "int*";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<short int*> {
  constexpr static const char* value = "short int*";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<long int*> {
  constexpr static const char* value = "long int*";
  constexpr operator const char*() const {
    return value;
  }
};

// reference
template <>
struct type_descriptor<char&> {
  constexpr static const char* value = "char&";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<int&> {
  constexpr static const char* value = "int&";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<short int&> {
  constexpr static const char* value = "short int&";
  constexpr operator const char*() const {
    return value;
  }
};

template <>
struct type_descriptor<long int&> {
  constexpr static const char* value = "long int&";
  constexpr operator const char*() const {
    return value;
  }
};
