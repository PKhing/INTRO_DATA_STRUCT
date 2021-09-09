#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> tab;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    tab.push_back(x);
  }
  sort(tab.begin(), tab.end());
  while (m--) {
    int x;
    scanf("%d", &x);
    auto ed = upper_bound(tab.begin(), tab.end(), x + k);
    auto st = lower_bound(tab.begin(), tab.end(), x - k);
    printf("%d ", ed - st);
  }
}