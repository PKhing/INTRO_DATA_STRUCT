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

 protected:
  node* mRoot;

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
  rope() : mRoot(new node()) {}
  rope(string s) : mRoot(new node(s)) {}
  //------------------Operations-----------------------
  void concat(rope r) { mRoot = merge(mRoot, r.mRoot); }

  void insert(size_t index, rope r) {
    node *left = NULL, *right = NULL;
    split(mRoot, left, right, index);
    mRoot = merge(merge(left, r.mRoot), right);
  }

  char index(size_t index) { return findIndex(mRoot, index); }

  rope substring(size_t st, size_t ed) {
    rope r;
    node* tmp;
    split(mRoot, r.mRoot, tmp, ed);
    cout << endl;
    cout << endl;
    printNode(r.mRoot);
    cout << endl;
    split(r.mRoot, tmp, r.mRoot, st);
    return r;
  }

  void erase(size_t st, size_t ed) {
    node *left, *mid, *right;
    split(mRoot, left, right, ed);
    split(left, left, mid, st);
    mRoot = merge(left, right);
  }

  //-----------------------Utils------------------------
  string toString() {
    string str;
    toString(mRoot, str);
    return str;
  }
  size_t length() { return length(mRoot); }
  void print() { printNode(mRoot); }
};

int main() {
  rope s1;
  rope s2("aa");

  cout << s1.toString() << endl;
  s1.concat(s2);
  s2.insert(0, rope("asdfas"));

  cout << s1.toString() << endl;
  s1.print();
  cout << s2.toString() << endl;
  s2.substring(0, 3).print();
  cout << s2.substring(0, 3).toString() << endl;
}