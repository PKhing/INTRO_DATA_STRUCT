#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a, int b) {
  int st = a, ed = b;
  while (st < ed) {
    std::swap(mData[(st + mFront) % mCap], mData[(ed + mFront) % mCap]);
    st++;
    ed--;
  }
}

#endif
