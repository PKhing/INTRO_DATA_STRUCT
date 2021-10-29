#include <bits/stdc++.h>
using namespace std;

int tab[105][105];
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tab[i][j];
    }
  }
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c || b > d) {
      cout << "INVALID" << endl;
    } else {
      int mx = -1e9;
      for (int i = max(a - 1, 0); i < min(c, n); i++) {
        for (int j = max(b - 1, 0); j < min(d, m); j++) {
          mx = max(mx, tab[i][j]);
        }
      }
      if (mx == -1e9) {
        cout << "OUTSIDE" << endl;
      } else {
        cout << mx << endl;
      }
    }
  }
}