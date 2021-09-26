#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  // write your code here
  mSize -= std::min(mSize, K);
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  std::stack<T> tmp;
  for (int i = std::max(0, (int)(mSize - K)); i < mSize; i++) {
    tmp.push(mData[i]);
  }
  mSize -= std::min(mSize, K);
  return tmp;
}

#endif
