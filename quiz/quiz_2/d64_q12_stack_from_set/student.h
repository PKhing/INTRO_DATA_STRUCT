#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

// DO NOT INCLUDE ANYTHING

template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,
                    typename std::set<T>::iterator last) {
  // write your code ONLY here
  auto tmp = first;
  int size = 0;
  while (tmp != last) {
    size++;
    tmp++;
  }
  mData = new T[size];
  mCap = size;
  mSize = size;
  int ptr = size - 1;
  while (first != last) {
    mData[ptr--] = *first++;
  }
}

#endif
