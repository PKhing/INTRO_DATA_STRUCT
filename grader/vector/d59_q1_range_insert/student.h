#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
  int insertSize = last - first;
  int newSize = mSize + insertSize;
  T* tmp = new T[newSize];
  int ptr = 0;
  for (auto i = begin(); i < position; i++) {
    tmp[ptr++] = *i;
  }
  while (first < last) {
    tmp[ptr++] = *first++;
  }
  for (auto i = position; i < end(); i++) {
    tmp[ptr++] = *i;
  }
  std::swap(tmp, mData);
  delete[] tmp;
  mSize = newSize;
  mCap = newSize;
}

#endif
