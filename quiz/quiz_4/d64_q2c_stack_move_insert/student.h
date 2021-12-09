#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m) {
  k = std::min(k, (int)mSize);
  m = std::min(m, (int)s2.mSize);

  expand(mSize + m);
  for (int i = 0; i < k; i++) {
    mData[mCap - i - 1] = mData[mSize - i - 1];
  }
  for (int i = 0; i < m; i++) {
    mData[mSize - k + i] = s2.mData[i + s2.mSize - m];
  }
  mSize = mSize + m;
  s2.mSize = s2.mSize - m;
}
#endif
