#include <bits/stdc++.h>
#define FOR(i, a) for (int i = 0; i < a; i++)
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int, int>
#define ll long long

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ii> section;
  FOR(i, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    section.pb(mp(a, b));
  }
  sort(all(section));

  while (q--) {
    int x;
    scanf("%d", &x);
    auto it = upper_bound(section.begin(), section.end(), mp(x, int(1e9)));

    if (it == section.begin()) {
      printf("0 ");
      continue;
    }
    it--;
    if (it->s >= x) {
      printf("1 ");
    } else {
      printf("0 ");
    }
  }
}