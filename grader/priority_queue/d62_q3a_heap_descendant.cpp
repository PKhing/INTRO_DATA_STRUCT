#include <bits/stdc++.h>
using namespace std;
void print(int i) {}
int main() {
  int n, a;
  cin >> n >> a;
  queue<int> q;
  q.push(a);
  vector<int> ans;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x >= n) continue;
    ans.push_back(x);
    q.push((x << 1) + 1);
    q.push((x << 1) + 2);
  }
  printf("%d\n", ans.size());
  for (auto x : ans) printf("%d ", x);
}