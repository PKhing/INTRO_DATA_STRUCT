#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  if (mSize != other.mSize) return 0;
  for (int i = 0; i < mSize; i++) {
    if (mData[(mFront + i) % mCap] !=
        other.mData[(other.mFront + i) % other.mCap])
      return 0;
  }
  return 1;
}

#endif
