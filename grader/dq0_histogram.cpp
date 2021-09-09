#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<string, int> mp;
  while (n--) {
    string x;
    cin >> x;
    mp[x]++;
  }
  for (auto i : mp) {
    if (i.second > 1) {
      cout << i.first << ' ' << i.second << endl;
    }
  }
}