#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  map<string, string> par;
  while (n--) {
    string a, b;
    cin >> a >> b;
    par[b] = a;
  }
  while (q--) {
    string a, b;
    cin >> a >> b;
    if (par[par[a]] == par[par[b]] && par[par[b]] != "" && a != b) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}