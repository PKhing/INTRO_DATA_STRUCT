#include <bits/stdc++.h>
using namespace std;
int T[1000005];
int n, k;
int tab[1000005];
void update(int p, int v) {
  for (int i = p; i < 1000005; i += i & -i) {
    T[i] += v;
  }
}

int query(int p) {
  int ans = 0;
  for (int i = p; i > 0; i -= i & -i) {
    ans += T[i];
  }
  return ans;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
  }

  for (int i = 0; i <= k; i++) {
    update(tab[i], 1);
  }

  for (int i = 0; i + k < n; i++) {
    int l = 1, r = 1000000;
    int ans = -1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (query(m) >= (k >> 1) + 1) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    printf("%d ", ans);
    update(tab[i], -1);
    if (i + k + 1 < n) update(tab[i + k + 1], 1);
  }
}