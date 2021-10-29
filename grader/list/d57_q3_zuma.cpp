#include <bits/stdc++.h>
using namespace std;
int tab[100005];
int main() {
  int n, k, v;
  cin >> n >> k >> v;
  tab[k] = v;
  for (int i = 0; i < n; i++) scanf("%d", &tab[i < k ? i : i + 1]);
  int st = k;
  int ed = k + 1;
  while (true) {
    int tmpst = st;
    int tmped = ed;
    int cnt = 0;
    while (tmpst >= 0 && tab[tmpst] == v) tmpst--, cnt++;
    while (tmped <= n && tab[tmped] == v) tmped++, cnt++;
    if (cnt >= 3) {
      st = tmpst;
      ed = tmped;
      if (tab[st] != tab[ed]) break;
      v = tab[st];
    } else
      break;
  }
  for (int i = 0; i <= st; i++) {
    printf("%d ", tab[i]);
  }
  for (int i = ed; i <= n; i++) {
    printf("%d ", tab[i]);
  }
}