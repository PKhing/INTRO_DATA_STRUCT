#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other) {
  std::swap(other.mCap, mCap);
  std::swap(other.mSize, mSize);
  std::swap(other.mData, mData);
}

#endif
