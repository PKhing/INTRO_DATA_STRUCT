#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a, b;
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    a.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    b.push_back(x);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ptr1 = 0;
  int ptr2 = 0;
  while (ptr1 != n && ptr2 != m) {
    while (ptr1 < n - 1 && a[ptr1] == a[ptr1 + 1]) ptr1++;
    while (ptr2 < n - 1 && b[ptr2] == b[ptr2 + 1]) ptr2++;
    if (a[ptr1] == b[ptr2]) {
      printf("%d ", a[ptr1]);
    }
    if (a[ptr1] < b[ptr2]) {
      ptr1++;
    } else if (a[ptr1] > b[ptr2]) {
      ptr2++;
    } else {
      ptr1++;
      ptr2++;
    }
  }
}