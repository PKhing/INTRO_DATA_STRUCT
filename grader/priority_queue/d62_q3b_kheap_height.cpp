#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, k;
  cin >> n >> k;
  if (k == 1)
    cout << endl << (long long)n - 1;
  else
    cout << ceil(log(n * (k - 1) + 1) / log(k) - 1);
}