#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    s.insert(x);
  }
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      int a;
      scanf("%d", &a);
      auto ptr = s.upper_bound(a);
      if (ptr == s.end()) {
        printf("%d", i);
        exit(0);
      }
      s.erase(ptr);
    }
  }
  printf("%d", m + 1);
}