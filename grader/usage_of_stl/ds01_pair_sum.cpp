#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    mp[x]++;
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    bool found = 0;
    for (auto y : mp) {
      if (mp.find(x - y.first) != mp.end()) {
        if (x == 2 * y.first && y.second < 2) {
          continue;
        } else {
          found = 1;
          break;
        }
      }
    }
    if (found) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}