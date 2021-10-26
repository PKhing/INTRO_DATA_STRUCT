#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>

const int k = 4;

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::fixUp(size_t idx) {
  T tmp = mData[idx];
  while (idx > 0 && mLess(mData[(idx - 1) / k], tmp)) {
    mData[idx] = mData[(idx - 1) / k];
    idx = (idx - 1) / k;
  }
  mData[idx] = tmp;
}

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::fixDown(size_t idx) {
  T tmp = mData[idx];
  int c;
  while ((c = k * idx + 1) < mSize) {
    int mx = c;
    for (int i = 1; i < k; i++) {
      if (c + i >= mSize) break;
      if (mLess(mData[mx], mData[c + i])) {
        mx = c + i;
      }
    }
    if (!mLess(tmp, mData[mx])) break;
    mData[idx] = mData[mx];
    idx = mx;
  }
  mData[idx] = tmp;
}

#endif
