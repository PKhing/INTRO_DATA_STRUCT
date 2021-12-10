#include <bits/stdc++.h>
using namespace std;

class rope {
  class node {
    friend class rope;

   protected:
    node *left, *right;
    string str;
    size_t weight;
    bool isLeaf() { return !left && !right; }

   public:
    node(string str)
        : str(str), weight(str.length()), left(NULL), right(NULL) {}
    node(node* left, node* right, size_t weight)
        : str(""), weight(weight), left(left), right(right) {}
    node() : str(""), weight(0), left(NULL), right(NULL) {}
  };
  class versionController {
    friend class rope;
    vector<node*> versions;
    size_t currentVersion;

   public:
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
    return new node(left, right, length(left));
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
    } else {
      left = new node(ptr->left, NULL, ptr->weight);
      split(ptr->right, left->right, right, index - ptr->weight);
    }
  }

  void splitNode(node* ptr, node*& left, node*& right, size_t idx) {
    left = new node(ptr->str.substr(0, idx));
    right = new node(ptr->str.substr(idx));
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
    printf("<%d>", ptr->weight);
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
    version.saveVersion(mRoot);
  }

  void insert(size_t index, rope r) {
    node *left = NULL, *right = NULL;
    split(mRoot, left, right, index);
    mRoot = merge(merge(left, r.mRoot), right);
    version.saveVersion(mRoot);
  }

  void erase(size_t st, size_t ed) {
    node *left, *mid, *right;
    split(mRoot, left, right, ed);
    split(left, left, mid, st);
    mRoot = merge(left, right);
    version.saveVersion(mRoot);
  }

  char index(size_t index) { return findIndex(mRoot, index); }

  rope substring(size_t st, size_t ed) {
    rope r;
    node* tmp;
    split(mRoot, r.mRoot, tmp, ed);
    split(r.mRoot, tmp, r.mRoot, st);
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
  s1.concat(rope("1234567890"));
  s1.erase(2, 3);
  s1.erase(4, 5);
  cout << s1.toString() << endl;
  s1.undo();
  cout << s1.toString() << endl;
  s1.undo();
  cout << s1.toString() << endl;
  s1.redo();
  cout << s1.toString() << endl;
  s1.concat(rope("bbb"));
  cout << s1.toString() << endl;
  s1.redo();
  cout << s1.toString() << endl;
  s1.undo();
  cout << s1.toString() << endl;
  s1.redo();
  cout << s1.toString() << endl;
  s1.undo();
  cout << s1.toString() << endl;
  s1.undo();
  cout << s1.toString() << endl;
  s1.undo();
  cout << s1.toString() << endl;
  s1.undo();
  cout << s1.toString() << endl;
  s1.undo();
  cout << s1.toString() << endl;
}