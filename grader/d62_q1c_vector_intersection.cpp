#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set<int> a, b;
  while (n--) {
    int x;
    scanf("%d", &x);
    a.insert(x);
  }

  while (m--) {
    int x;
    scanf("%d", &x);
    b.insert(x);
  }

  for (auto i : a) {
    if (b.find(i) != b.end()) {
      printf("%d ", i);
    }
  }
}