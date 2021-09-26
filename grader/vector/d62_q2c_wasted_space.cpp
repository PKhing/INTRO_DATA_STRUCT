#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0;
  cin >> n;
  while ((n >> i) > 0 && (1 << i) != n) i++;
  printf("%d", (1 << i) - n);
}