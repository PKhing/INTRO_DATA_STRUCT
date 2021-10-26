#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n >> m;
  while (m--) {
    scanf("%d %d", &a, &b);
    if (a == b) {
      cout << "a and b are the same node\n";
    } else if (a > b) {
      while (a > b) {
        a = (a - 1) >> 1;
      }
      if (a == b)
        cout << "b is an ancestor of a\n";
      else
        cout << "a and b are not related\n";
    } else {
      while (b > a) {
        b = (b - 1) >> 1;
      }
      if (a == b)
        cout << "a is an ancestor of b\n";
      else
        cout << "a and b are not related\n";
    }
  }
}