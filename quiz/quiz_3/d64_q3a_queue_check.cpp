#include <bits/stdc++.h>
using namespace std;
int mFront, mSize, mCap, last, correction;

bool check() {
  if (mFront >= mCap) return false;
  if (mSize > mCap) return false;
  if (last >= mCap) return false;
  if (last != (mFront + mSize) % mCap) return false;
  return true;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    cin >> mFront >> mSize >> mCap >> last >> correction;
    if (check()) {
      printf("OK");
    } else {
      if (!correction) {
        printf("WRONG");
      } else if (correction == 1) {
        printf("WRONG %d", (last - mSize + mCap) % mCap);
      } else if (correction == 2) {
        printf("WRONG %d", (last - mFront + mCap) % mCap);
      } else if (correction == 3) {
        if (mFront + mSize == last) {
          printf("WRONG %d", max(mFront + 1, max(mSize, last + 1)));
        } else {
          printf("WRONG %d", mFront + mSize - last);
        }
      } else {
        printf("WRONG %d", (mFront + mSize) % mCap);
      }
    }
    printf("\n");
  }
}