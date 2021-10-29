#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define f first
#define s second

ii sum(ii a, ii b) { return make_pair(a.f + b.f, a.s + b.s); }

int main() {
  map<string, pair<int, int>> teacher, subject;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t, s;
    int pt;
    cin >> s >> t >> pt;
    teacher[t] = sum(teacher[t], make_pair(pt, 1));
    subject[s] = sum(subject[s], make_pair(pt, 1));
  }
  for (auto i : subject) {
    cout << i.f;
    printf(" %.2lf\n", (double)i.s.f / i.s.s);
  }
  for (auto i : teacher) {
    cout << i.f;
    printf(" %.2lf\n", (double)i.s.f / i.s.s);
  }
}