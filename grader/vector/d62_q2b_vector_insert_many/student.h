#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
  // write your code here
  sort(data.begin(), data.end());
  int newSize = mSize + data.size();
  T* tmp = new T[newSize]();
  int ptr = 0;
  int dataPtr = 0;
  for (int i = 0; i <= mSize; i++) {
    if (data[dataPtr].first == i) {
      tmp[ptr++] = data[dataPtr++].second;
    }
    if (i < mSize) {
      tmp[ptr++] = mData[i];
    }
  }
  std::swap(tmp, mData);

  delete[] tmp;
  mCap = newSize;
  mSize = newSize;
}

#endif
