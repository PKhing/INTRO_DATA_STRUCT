#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int t[1000005];
int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
    pq.push(make_pair(0, i));
  }
  for (int i = 0; i < m; i++) {
    int time = pq.top().first;
    int chef = pq.top().second;
    printf("%d\n", time);
    pq.pop();
    pq.push(make_pair(time + t[chef], chef));
  }
}