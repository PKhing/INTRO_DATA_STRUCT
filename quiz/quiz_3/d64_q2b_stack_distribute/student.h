#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <math.h>
template <typename T>

std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  std::vector<std::vector<T>> answer;
  int ptr = 0;
  for (int i = 0; i < k; i++) {
    std::vector<T> tmp;
    int size = mSize - ptr;
    for (int j = 0; j < ceil((double)size / (double)(k - i)); j++) {
      tmp.push_back(mData[mSize - (ptr++) - 1]);
    }
    answer.push_back(tmp);
  }
  return answer;
}
#endif
