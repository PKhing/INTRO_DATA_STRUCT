#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  for (auto &x : ls) {
    mHeader->prev->next = x.mHeader->next;
    x.mHeader->next->prev = mHeader->prev;
    mHeader->prev = x.mHeader->prev;
    x.mHeader->prev->next = mHeader;
    x.mHeader->prev = x.mHeader;
    x.mHeader->next = x.mHeader;
    mSize += x.size();
    x.mSize = 0;
  }
}

#endif
