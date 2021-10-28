#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
  int size = std::min(mSize, size_t(7));
  T tmp[size];
  for (int i = 0; i < size; i++) tmp[i] = mData[i];
  std::sort(tmp, tmp + size, mLess);
  return tmp[size - k];
}

#endif
