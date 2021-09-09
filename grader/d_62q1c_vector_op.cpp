#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return b < a; }
int main() {
  int q;
  cin >> q;
  vector<int> v;
  while (q--) {
    string cmd;
    cin >> cmd;
    if (cmd == "pb") {
      int c;
      cin >> c;
      v.push_back(c);
    }
    if (cmd == "sa") {
      sort(v.begin(), v.end());
    }
    if (cmd == "sd") {
      sort(v.begin(), v.end(), cmp);
    }
    if (cmd == "r") {
      reverse(v.begin(), v.end());
    }
    if (cmd == "d") {
      int i;
      cin >> i;
      v.erase(v.begin() + i);
    }
  }
  for (auto i : v) cout << i << ' ';
}