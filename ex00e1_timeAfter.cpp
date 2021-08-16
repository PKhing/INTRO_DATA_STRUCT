#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, m, pl;
  cin >> h >> m >> pl;
  m += pl;
  h += m / 60;
  m %= 60;
  h %= 24;
  printf("%02d %02d", h, m);
}