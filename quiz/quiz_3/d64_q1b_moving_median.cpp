#include <bits/stdc++.h>
using namespace std;
int tab[1000005];
int main() {
  int n, w;
  multiset<int> s1, s2;
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
  }
  for (int i = 0; i <= w; i++) {
    s1.insert(tab[i]);
  }
  for (int i = 0; i + w < n; i++) {
    while (s1.size() > s2.size()) {
      s2.insert(*(--s1.end()));
      s1.erase((--s1.end()));
    }
    while (s2.size() > s1.size()) {
      s1.insert(*s2.begin());
      s2.erase(s2.begin());
    }
    int ans = *(--s1.end());
    printf("%d ", ans);
    if (s1.find(tab[i]) != s1.end()) {
      s1.erase(s1.find(tab[i]));
    } else {
      s2.erase(s2.find(tab[i]));
    }
    if (i + w + 1 < n) {
      if (tab[i + w + 1] <= ans) {
        s1.insert(tab[i + w + 1]);
      } else {
        s2.insert(tab[i + w + 1]);
      }
    }
  }
}
