
typedef struct value {
  KeyT val;
  int mxDiff, height;
  value(KeyT val, int mxDiff, int height)
      : val(val), mxDiff(mxDiff), height(height) {}
} value;
// Your code here
value getValue(node* x) {
  if (!x) return value(KeyT(), -1, -1);
  value l = getValue(x->left), r = getValue(x->right);
  value ans(KeyT(), std::max(l.mxDiff, r.mxDiff),
            std::max(l.height, r.height) + 1);
  if (l.mxDiff > r.mxDiff) {
    ans.val = l.val;
  } else if (l.mxDiff == r.mxDiff) {
    ans.val = std::min(l.val, r.val);
  } else {
    ans.val = r.val;
  }
  if (abs(l.height - r.height) > ans.mxDiff) {
    ans.mxDiff = abs(l.height - r.height);
    ans.val = x->data.first;
  } else if (abs(l.height - r.height) == ans.mxDiff) {
    ans.val = std::min(x->data.first, ans.val);
  }
  return ans;
}

KeyT getValueOfMostImbalanceNode() {
  // Your code here
  value ans = getValue(mRoot);

  return ans.val;
}
