#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator==(const vector<T> &other) const {
  // write your code only in this function
  if (mSize != other.size()) return 0;
  for (int i = 0; i < mSize; i++) {
    if (other[i] != mData[i]) return 0;
  }
  return 1;
}

#endif
