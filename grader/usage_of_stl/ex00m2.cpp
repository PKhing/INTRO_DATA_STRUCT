#include <bits/stdc++.h>
#define ii pair<int, int>
#define f first
#define s second
using namespace std;

map<ii, int> mp;
int k[1000005];
vector<int> ans[1000005];
priority_queue<ii> pq[1000005];
int main() {
  int n, m, a;
  cin >> n >> m >> a;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k[i]);
  }
  for (int i = 0; i < a; i++) {
    char action;
    cin >> action;
    if (action == 'B') {
      int u, x, v;
      cin >> u >> x >> v;
      mp[make_pair(u, x)] = v;
    } else {
      int u, x;
      cin >> u >> x;
      mp.erase(make_pair(u, x));
    }
  }
  for (auto i : mp) {
    pq[i.f.s].push(make_pair(i.s, i.f.f));
  }
  for (int i = 1; i <= n; i++) {
    while (!pq[i].empty() && k[i]) {
      ans[pq[i].top().second].push_back(i);
      pq[i].pop();
      k[i]--;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (ans[i].size() == 0) {
      printf("NONE");
    }
    for (auto x : ans[i]) {
      printf("%d ", x);
    }
    printf("\n");
  }
}