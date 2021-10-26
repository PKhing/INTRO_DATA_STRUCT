#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if (m > 0 && a >= begin() && b >= begin() && a < end() && b < end() &&
      a + m - 1 < end() && b + m - 1 < end() && a + m - 1 >= begin() &&
      b + m - 1 >= begin()) {
    if ((a < b && a + m - 1 < b) || (b < a && b + m - 1 < a)) {
      for (int i = 0; i < m; i++) {
        int tmp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = tmp;
      }
      return true;
    } else {
      return false;
    }
  }
  return false;
}

#endif
