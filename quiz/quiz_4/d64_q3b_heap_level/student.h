#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T, typename Comp>
std::vector<T> CP::priority_queue<T, Comp>::at_level(size_t k) const {
  // write your code here
  // can include anything
  std::vector<T> r;
  CP::priority_queue<T, Comp> tmp(mLess);
  for (double i = (1 << k) - 1; i < (1 << (k + 1)) - 1 && i < mSize; i++) {
    tmp.push(mData[(int)i]);
  }
  while (!tmp.empty()) r.push_back(tmp.top()), tmp.pop();
  return r;
}

#endif
