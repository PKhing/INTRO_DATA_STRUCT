#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value, iterator a, iterator b,
                          CP::list<T>& output) {
  // write your code here
  while (a != b) {
    if (*a == value) {
      node* tmp = new node(value, output.mHeader, output.mHeader->next);
      output.mHeader->next->prev = tmp;
      output.mHeader->next = tmp;
      output.mSize++;

      tmp = a.ptr->next;
      a.ptr->prev->next = a.ptr->next;
      a.ptr->next->prev = a.ptr->prev;
      delete a.ptr;
      a = iterator(tmp);
      mSize--;
    } else {
      a++;
    }
  }
}

#endif
