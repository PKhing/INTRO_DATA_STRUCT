#ifndef __STUDENT_H_
#define __STUDENT_H_

// you can include any other file here
// you are allow to use any data structure
#include <set>
template <typename T>
void CP::vector<T>::uniq() {
  T* tmp = new T[mSize];
  int newSize = 0;
  std::set<T> appeared;
  for (int i = 0; i < mSize; i++) {
    if (appeared.find(mData[i]) == appeared.end()) {
      appeared.insert(mData[i]);
      tmp[newSize++] = mData[i];
    }
  }
  std::swap(tmp, mData);
  delete[] tmp;
  mCap = mSize;
  mSize = newSize;
}

#endif
