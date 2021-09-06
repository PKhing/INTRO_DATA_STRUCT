#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
void list_erase(vector<int> &v, vector<int> &pos) {
  // write your code here
  vector<int> v2;
  sort(pos.begin(), pos.end());
  int ptr = 0;
  for (int i = 0; i < v.size(); i++) {
    if (ptr < pos.size() && pos[ptr] == i) {
      ptr++;
      continue;
    }
    v2.push_back(v[i]);
  }
  v = v2;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n), pos(m);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < m; i++) cin >> pos[i];
  list_erase(v, pos);
  cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
  for (auto &x : v) cout << x << " ";
  cout << endl;
}