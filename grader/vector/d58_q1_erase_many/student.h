#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int>& pos) {
  // write your code here
  std::vector<int> sortedPos = pos;
  sort(sortedPos.begin(), sortedPos.end());
  T* tmp = new T[mSize];
  int ptr = 0;
  int posPtr = 0;
  for (int i = 0; i < mSize; i++) {
    if (posPtr < sotredPos.size() && sortedPos[posPtr] == i) {
      posPtr++;
    } else {
      tmp[ptr++] = mData[i];
    }
  }
  std::swap(mData, tmp);
  mCap = mSize;
  mSize = ptr;
}

#endif
