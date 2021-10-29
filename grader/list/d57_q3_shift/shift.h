void shift(int k) {
  // TODO: Add your code here
  k = ((k % (int)mSize) + (int)mSize) % (int)mSize;
  auto it = begin().ptr;
  while (k--) {
    it = it->next;
  }

  mHeader->prev->next = mHeader->next;
  mHeader->next->prev = mHeader->prev;

  mHeader->next = it;
  mHeader->prev = it->prev;
  it->prev->next = mHeader;
  it->prev = mHeader;
}
