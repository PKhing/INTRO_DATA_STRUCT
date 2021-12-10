#include <bits/stdc++.h>
using namespace std;

class fibonacciSequence {
  vector<size_t> sequence;

 public:
  fibonacciSequence() {
    sequence.push_back(0);
    sequence.push_back(1);
  }
  size_t get(size_t index) {
    while (sequence.size() <= index) {
      sequence.push_back(sequence[sequence.size() - 1] +
                         sequence[sequence.size() - 2]);
    }
    return sequence[index];
  }
  size_t getIndex(size_t x) {
    if (x > sequence[sequence.size() - 1]) {
      while (sequence[sequence.size() - 1] <= x) {
        sequence.push_back(sequence[sequence.size() - 1] +
                           sequence[sequence.size() - 2]);
      }
      return sequence.size() - 1;
    }
    int l = 0, r = sequence.size() - 1;
    size_t ans = 0;
    while (l <= r) {
      int m = (l + r) / 2;
      if (x < sequence[m])
        r = m - 1;
      else
        ans = m, l = m + 1;
    }
    return ans;
  }
};

fibonacciSequence fibo;
class rope {
  class node {
    friend class rope;

   protected:
    node *left, *right;
    string str;
    size_t weight;
    char depth;

   public:
    //-----------------------Constructor---------------------------------
    node(string str)
        : str(str), weight(str.length()), left(NULL), right(NULL), depth(0) {}
    node(node* left, node* right, size_t weight)
        : str(""), weight(weight), left(left), right(right), depth(0) {}
    node() : str(""), weight(0), left(NULL), right(NULL), depth(0) {}

    //--------------------------Utils--------------------------------
    bool isLeaf() { return !left && !right; }
    void updateDepth() {
      if (!left && !right)
        depth = 0;
      else
        depth = max(left ? left->depth : 0, right ? right->depth : 0) + 1;
    }
  };
  class versionController {
    friend class rope;
    vector<node*> versions;
    size_t currentVersion;

   public:
    //--------------------Constructor---------------------
    versionController(node* mRoot) : currentVersion(0) {
      versions.push_back(mRoot);
    }
    //-------------------Operations----------------------
    node* undo() {
      if (currentVersion > 0) currentVersion--;
      return versions[currentVersion];
    }
    node* redo() {
      if (currentVersion < versions.size() - 1) currentVersion++;
      return versions[currentVersion];
    }
    node* saveVersion(node* mRoot) {
      versions.resize(currentVersion + 1);
      versions.push_back(mRoot);
      currentVersion++;
    }
  };

 protected:
  node* mRoot;
  versionController version;

  //------------------------Merge--------------------------------
  node* merge(node* left, node* right) {
    if (!left) return right;
    if (!right) return left;
    node* tmp = new node(left, right, length(left));
    tmp->updateDepth();
    return tmp;
  }

  //-------------------------Split-------------------------------
  void split(node* ptr, node*& left, node*& right, size_t index) {
    if (ptr->isLeaf()) {
      splitNode(ptr, left, right, index);
      return;
    }
    if (index < ptr->weight) {
      right = new node(NULL, ptr->right, ptr->weight - index);
      split(ptr->left, left, right->left, index);
      right->updateDepth();
    } else {
      left = new node(ptr->left, NULL, ptr->weight);
      split(ptr->right, left->right, right, index - ptr->weight);
      left->updateDepth();
    }
  }

  void splitNode(node* ptr, node*& left, node*& right, size_t index) {
    left = new node(ptr->str.substr(0, index));
    right = new node(ptr->str.substr(index));
  }
  //-------------------------Rebalance---------------------------
  typedef priority_queue<pair<int, node*>, vector<pair<int, node*>>,
                         greater<pair<int, node*>>>
      rebalancepq;
  void rebalance() {
    if (length() >= fibo.get(mRoot->depth + 2)) return;
    rebalancepq pq;
    rebalance(pq, mRoot);
    mRoot = NULL;
    while (!pq.empty()) {
      mRoot = merge(pq.top().second, mRoot);
      pq.pop();
    }
    if (!mRoot) mRoot = new node();
  }
  void rebalance(rebalancepq& pq, node* ptr) {
    if (!ptr) return;
    if (ptr->isLeaf()) {
      if (ptr->weight == 0) return;
      int index = fibo.getIndex(ptr->weight);
      node* tmp = NULL;
      while (!pq.empty() && pq.top().first < index)
        tmp = merge(pq.top().second, tmp), pq.pop();
      ptr = merge(tmp, ptr);
      while (!pq.empty() && pq.top().first == index) {
        ptr = merge(pq.top().second, ptr);
        index++;
        pq.pop();
      }

      pq.push(make_pair(index, ptr));
      return;
    }
    rebalance(pq, ptr->left);
    rebalance(pq, ptr->right);
  }

  // --------------------------Utils--------------------------
  void toString(node* ptr, string& str) {
    if (!ptr) return;
    if (ptr->isLeaf()) {
      str.append(ptr->str);
      return;
    }
    toString(ptr->left, str);
    toString(ptr->right, str);
  }

  void printNode(node* ptr, size_t depth = 0) {
    if (!ptr) return;
    printNode(ptr->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("==");
    printf("<%d/%d>", ptr->weight, ptr->depth);
    cout << ptr->str << endl;
    printNode(ptr->left, depth + 1);
  }

  size_t length(node* ptr) {
    if (!ptr->right) return ptr->weight;
    return ptr->weight + length(ptr->right);
  }

  char findIndex(node* ptr, size_t index) {
    if (ptr->isLeaf()) return ptr->str[index];
    if (index < ptr->weight)
      return findIndex(ptr->left, index);
    else
      return findIndex(ptr->right, index - ptr->weight);
  }

 public:
  //------------------Constructor----------------------
  rope() : mRoot(new node()), version(mRoot) {}
  rope(string s) : mRoot(new node(s)), version(mRoot) {}
  //------------------Operations-----------------------
  void concat(rope r) {
    mRoot = merge(mRoot, r.mRoot);
    rebalance();
    version.saveVersion(mRoot);
  }

  void insert(size_t index, rope r) {
    node *left = NULL, *right = NULL;
    split(mRoot, left, right, index);
    mRoot = merge(merge(left, r.mRoot), right);
    rebalance();
    version.saveVersion(mRoot);
  }

  void erase(size_t st, size_t ed) {
    node *left, *mid, *right;
    split(mRoot, left, right, ed);
    split(left, left, mid, st);
    mRoot = merge(left, right);
    rebalance();
    version.saveVersion(mRoot);
  }

  char index(size_t index) { return findIndex(mRoot, index); }

  rope substring(size_t st, size_t ed) {
    rope r;
    node* tmp;
    split(mRoot, r.mRoot, tmp, ed);
    split(r.mRoot, tmp, r.mRoot, st);
    r.rebalance();
    return r;
  }

  //-----------------------Utils------------------------
  string toString() {
    string str;
    toString(mRoot, str);
    return str;
  }
  size_t length() { return length(mRoot); }
  void print() { printNode(mRoot); }

  //------------------------Persistent-------------------
  void undo() { mRoot = version.undo(); }
  void redo() { mRoot = version.redo(); }
};

int main() {
  rope s1;
  s1.concat(rope("1"));
  s1.concat(rope("234"));
  s1.concat(rope("5"));
  s1.concat(rope("6"));
  s1.concat(rope("78"));
  s1.concat(rope("91011"));
  s1.concat(rope("1213"));
  s1.concat(rope("1"));
  s1.concat(rope("234"));
  s1.concat(rope("5"));
  s1.concat(rope("6"));
  s1.concat(rope("78"));
  s1.concat(rope("91011"));
  s1.concat(rope("1213"));
  cout << s1.toString() << endl;
  cout << s1.substring(10, 20).toString();
}