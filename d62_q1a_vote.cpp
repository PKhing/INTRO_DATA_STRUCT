#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  map<string, int> mp;
  vector<int> cnt;
  while (n--) {
    string s;
    cin >> s;
    mp[s]++;
  }
  for (auto i : mp) {
    cnt.push_back(i.second);
  }
  sort(cnt.begin(), cnt.end());
  cout << cnt[max(0, (int)cnt.size() - k)];
}