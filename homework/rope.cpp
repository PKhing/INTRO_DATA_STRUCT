#include <bits/stdc++.h>
using namespace std;
class rope {
  class node {
    friend class rope;

   protected:
    node *left, *right;
    string str;
    size_t weight;

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
    if (!ptr) return;
    if (!ptr->left) {
      splitNode(ptr, left, right, index);
      return;
    }

    if (index < ptr->weight) {
      split(ptr->left, left, ptr->left, index);
      ptr->weight -= index;
      right = ptr;
    } else {
      split(ptr->right, ptr->right, right, index - ptr->weight);
      left = ptr;
    }
  }

  void splitNode(node* ptr, node*& left, node*& right, size_t idx) {
    if (idx == 0) {
      left = NULL;
      right = ptr;
      return;
    }
    left = new node(ptr->str.substr(0, idx));
    right = new node(ptr->str.substr(idx));
    delete ptr;
  }
  // --------------------------Utils--------------------------
  void toString(node* ptr, string& str) {
    if (!ptr) return;
    if (!ptr->left) {
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
    if (!ptr->left) return ptr->str[index];
    if (index < ptr->weight)
      return findIndex(ptr->left, index);
    else
      return findIndex(ptr->right, index - ptr->weight);
  }

  void clear(node* ptr) {
    if (!ptr) return;
    clear(ptr->left);
    clear(ptr->right);
    delete ptr;
  }

 public:
  //------------------Constructor----------------------
  rope() : mRoot(new node()) {}
  rope(string s) : mRoot(new node(s)) {}
  //------------------Operations-----------------------
  void concat(rope r) { mRoot = merge(mRoot, r.mRoot); }

  void insert(size_t index, rope r) {
    node *left, *right;
    split(mRoot, left, right, index);
    mRoot = merge(left, r.mRoot);
    mRoot = merge(mRoot, right);
  }

  char index(size_t index) { return findIndex(mRoot, index); }

  void split(size_t index, rope& r) {
    node *left, *right;
    split(mRoot, left, right, index);
    mRoot = left;
    r.mRoot = right;
  }

  void erase(size_t st, size_t ed) {
    node *left, *mid, *right;
    split(mRoot, left, right, ed);
    split(left, left, mid, st);
    clear(mid);
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
  rope s("111111");
  s.concat(rope("2222"));
  s.concat(rope("33333"));
  s.concat(rope("4444"));
  s.concat(rope("55555"));
  s.insert(2, rope("adsjfkasjdlfa"));
  cout << s.toString() << endl;
  s.erase(5, 7);
  cout << s.toString() << endl;
}