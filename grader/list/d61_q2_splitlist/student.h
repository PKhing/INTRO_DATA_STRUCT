void splitList(list<T>& list1, list<T>& list2) {
  int size1 = (mSize - 1) / 2;
  node* st1 = mHeader->next;
  node* ed1 = st1;
  while (size1 > 0) {
    ed1 = ed1->next;
    size1--;
  }
  node* st2 = ed1->next;
  node* ed2 = mHeader->prev;
  if ((mSize + 1) / 2 >= 1) {
    list1.mHeader->prev->next = st1;
    st1->prev = list1.mHeader->prev;
    list1.mHeader->prev = ed1;
    ed1->next = list1.mHeader;
    list1.mSize += (mSize + 1) / 2;
  }
  if (mSize / 2 >= 1) {
    list2.mHeader->prev->next = st2;
    st2->prev = list2.mHeader->prev;
    list2.mHeader->prev = ed2;
    ed2->next = list2.mHeader;
    list2.mSize += mSize / 2;
  }

  mHeader->next = mHeader;
  mHeader->prev = mHeader;
  mSize = 0;
}