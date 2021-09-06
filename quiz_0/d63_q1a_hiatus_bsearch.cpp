#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

pair<int, int> tab[200005];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &tab[i].f, &tab[i].s);
  }
  sort(tab, tab + n);
  while (m--) {
    pair<int, int> x;
    scanf("%d %d", &x.f, &x.s);
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (tab[m] <= x) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (ans == -1) {
      printf("-1 -1 ");
    } else if (tab[ans] == x) {
      printf("0 0 ");
    } else {
      printf("%d %d ", tab[ans].f, tab[ans].s);
    }
  }
}