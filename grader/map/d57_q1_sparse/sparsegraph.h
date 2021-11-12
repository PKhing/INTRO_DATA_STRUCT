#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <vector>
#include <set>

using namespace std;

class SparseGraph {
 public:
  SparseGraph() : SparseGraph(3) {}

  SparseGraph(int n_in) : n(n_in) {}

  SparseGraph(const SparseGraph& G) : n(G.n), edge(G.edge) {}

  void AddEdge(int a, int b) { edge.insert(get_pair(a, b)); }

  void RemoveEdge(int a, int b) { edge.erase(get_pair(a, b)); }

  bool DoesEdgeExist(int a, int b) const {
    return edge.find(get_pair(a, b)) != edge.end();
  }

  SparseGraph Transpose() const {
    SparseGraph G(*this);
    G.isTranspose = !isTranspose;
    return G;
  }

 protected:
  pair<int, int> get_pair(int a, int b) const {
    if (isTranspose) {
      return make_pair(a, b);
    }
    return make_pair(b, a);
  }
  // Your code here
  int n;
  set<pair<int, int>> edge;
  bool isTranspose = false;
};
#endif  // __SPARSE_GRAPH_H__
