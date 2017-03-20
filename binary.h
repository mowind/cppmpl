// Copyright 2017, wjw
// All rights reserved.
// 
// Author: wjinwen.1988@gmail.com

#ifndef CPPMPL_INCLUDE_BINARY_H
#define CPPMPL_INCLUDE_BINARY_H

template <unsigned long N>
struct binary {
  static unsigned long const value 
      = binary<N/10>::value * 2   // 将高位移到低位
      + N % 10;
};

template <>
struct binary<0> {
  static unsigned long const value = 0;  // 特化，终结递归
};

#endif  // CPPMPL_INCLUDE_BINARY_H
