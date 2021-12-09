#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>
#include <string>
#include "priority_queue.h"
#include "student.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  CP::priority_queue<int> pq;

  int k;
  cin >> k;
  for (int i = 0; i < 10; i++) pq.push(i);

  std::vector<int> r = pq.at_level(k);
  cout << "size = " << r.size() << endl;
  for (auto &x : r) {
    cout << x << " ";
  }
  cout << endl;
}
