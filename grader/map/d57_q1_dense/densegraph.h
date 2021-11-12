#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
#include <stdio.h>
using namespace std;
class DenseGraph {
 public:
  DenseGraph() : DenseGraph(3) {}

  DenseGraph(int n_in) {
    n = n_in;
    tab = new bool*[n];
    for (int i = 0; i < n; i++) {
      tab[i] = new bool[n]();
    }
  }

  DenseGraph(const DenseGraph& G) : DenseGraph(G.n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) tab[i][j] = G.tab[i][j];
  }

  void AddEdge(int a, int b) { tab[a][b] = 1; }

  void RemoveEdge(int a, int b) { tab[a][b] = 0; }

  bool DoesEdgeExist(int a, int b) const { return tab[a][b]; }

  DenseGraph Transpose() const {
    DenseGraph G(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        G.tab[i][j] = tab[j][i];
      }
    }
    return G;
  }

 protected:
  int n;
  bool** tab;
  // Your code here
};
#endif  // __DENSE_GRAPH_H__
