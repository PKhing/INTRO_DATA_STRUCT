#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    mp[s]++;
  }
  int mx = 0;
  string ans = "";
  for (auto i : mp) {
    if (i.second >= mx) {
      mx = i.second;
      ans = i.first;
    }
  }
  cout << ans << ' ' << mx;
}