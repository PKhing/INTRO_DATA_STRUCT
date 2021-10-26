#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <math.h>
#include <algorithm>

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::find(T k) const {
  return std::find(mData, mData + mSize, k) != mData + mSize;
}

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::find_level(T k) const {
  int idx = -1;
  for (int i = mSize - 1; i >= 0; i--) {
    if (mData[i] == k) {
      idx = i;
      break;
    }
  }
  if (idx == -1) return -1;
  return ceil(log2(idx + 2) - 1);
}

#endif
