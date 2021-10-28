#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  // write your code here
  int size = last - first;
  T *tmp = new T[size];
  for (int i = 0; i < k; i++) {
    tmp[size - k + i] = *(first + i);
  }
  for (int i = k; i < size; i++) {
    tmp[i - k] = *(first + i);
  }
  for (int i = 0; i < size; i++) {
    *(first + i) = tmp[i];
  }

  delete[] tmp;
}

#endif
