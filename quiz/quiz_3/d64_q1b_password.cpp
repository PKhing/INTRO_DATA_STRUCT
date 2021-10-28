#include <bits/stdc++.h>
using namespace std;
int k[100005];
int n, m, l;

string encrypt(string s) {
  for (int i = 0; i < l; i++) {
    s[i] = (int)(s[i] - 'a' + k[i]) % 26 + 'a';
  }
  return s;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  set<string> db;
  string s;
  cin >> n >> m >> l;
  for (int i = 0; i < l; i++) cin >> k[i];
  while (n--) {
    cin >> s;
    db.insert(s);
  }
  while (m--) {
    cin >> s;
    string pw = encrypt(s);
    if (db.find(pw) != db.end()) {
      printf("Match\n");
    } else {
      printf("Unknown\n");
    }
  }
}