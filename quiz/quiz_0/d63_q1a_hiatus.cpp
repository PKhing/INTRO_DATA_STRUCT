#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> tab;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    tab.push_back(make_pair(a, b));
  }
  sort(tab.begin(), tab.end());
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    auto it = lower_bound(tab.begin(), tab.end(), make_pair(a, b));
    if (*it == make_pair(a, b)) {
      printf("0 0 ");
    } else {
      if (it == tab.begin()) {
        printf("-1 -1 ");
      } else {
        it--;
        printf("%d %d ", it->first, it->second);
      }
    }
  }
}