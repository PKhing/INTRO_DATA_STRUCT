void replace(const T& x, list<T>& y) {
  iterator it = begin();
  while (it != end()) {
    if (*it == x) {
      it = erase(it);
      for (auto value : y) {
        it = ++insert(it, value);
      }
    } else {
      it++;
    }
  }
}
