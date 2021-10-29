#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int, int> > v) {
  stack<int> s;
  for (auto i : v) {
    if (i.first == 0) {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      switch (i.second) {
        case 0:
          s.push(a + b);
          break;
        case 1:
          s.push(a - b);
          break;
        case 2:
          s.push(a * b);
          break;
        case 3:
          s.push(a / b);
          break;
      }
    } else {
      s.push(i.second);
    }
  }
  return s.top();
}

#endif
