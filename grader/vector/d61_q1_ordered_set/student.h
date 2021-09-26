#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
  vector<T> v;
  set<T> appeared;
  for (auto& x : A) {
    v.push_back(x);
    appeared.insert(x);
  }
  for (auto& x : B) {
    if (appeared.find(x) == appeared.end()) v.push_back(x);
  }
  return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
  vector<T> v;
  set<T> appeared;
  for (auto& x : B) {
    appeared.insert(x);
  }
  for (auto& x : A) {
    if (appeared.find(x) != appeared.end()) v.push_back(x);
  }
  return v;
}
