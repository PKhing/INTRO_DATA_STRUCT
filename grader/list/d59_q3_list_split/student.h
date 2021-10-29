#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it, size_t pos) {
  // write your code here
  CP::list<T> result;

  if (it == end()) return result;

  node *ed1 = it.ptr->prev;
  node *st = it.ptr;
  node *ed = (--end()).ptr;

  result.mHeader->next = st;
  result.mHeader->prev = ed;
  st->prev = result.mHeader;
  ed->next = result.mHeader;
  result.mSize = mSize - pos;

  ed1->next = mHeader;
  mHeader->prev = ed1;
  mSize = pos;

  return result;
}

#endif
