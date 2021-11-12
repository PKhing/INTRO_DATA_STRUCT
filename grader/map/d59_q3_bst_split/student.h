#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT, typename MappedT, typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT>
CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
  // your code here
  CP::map_bst<KeyT, MappedT, CompareT> result;
  node* ptr = mRoot;
  node* leftPtr = NULL;
  node* rightPtr = NULL;
  mRoot = NULL;
  while (ptr != NULL) {
    if (ptr->data.first < val) {
      child_link(ptr->parent, ptr->data.first) = NULL;
      child_link(leftPtr, ptr->data.first) = ptr;
      ptr->parent = leftPtr;
      leftPtr = ptr;
      ptr = ptr->right;
    } else {
      child_link(ptr->parent, ptr->data.first) = NULL;
      result.child_link(rightPtr, ptr->data.first) = ptr;
      ptr->parent = rightPtr;
      rightPtr = ptr;
      ptr = ptr->left;
    }
  }
  return result;
}

#endif
