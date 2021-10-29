#include <iostream>
#include "list.h"
using namespace std;

int main() {
  CP::list<int> x, a, b;
  int nx, na, nb;
  cin >> nx >> na >> nb;
  int tmp;
  while (nx--) {
    cin >> tmp;
    x.push_back(tmp);
  }
  while (na--) {
    cin >> tmp;
    a.push_back(tmp);
  }
  while (nb--) {
    cin >> tmp;
    b.push_back(tmp);
  }

  x.splitList(a, b);
  cout << "x is" << endl;
  cout << x.size() << endl;
  x.print();
  cout << "a is" << endl;
  cout << a.size() << endl;
  a.print();
  cout << "b is" << endl;
  cout << a.size() << endl;
  b.print();
  return 0;
}
