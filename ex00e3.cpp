#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (s.find(x) == s.end()) {
      s.insert(x);
    } else {
      printf("NO");
      return 0;
    }
    if (x <= 0 || x > n) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
}