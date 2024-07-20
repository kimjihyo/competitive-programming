#include <vector>
using namespace std;

struct DisjointSet {
  vector<int> parents;
  vector<int> ranks;

  DisjointSet(int maxSize) {
    parents.resize(maxSize);
    ranks.resize(maxSize);
    for (int i = 0; i < maxSize; i++) {
      parents[i] = i;
      ranks[i] = 1;
    }
  }

  int findSet(int v) {
    if (v == parents[v])
      return v;
    return parents[v] = findSet(parents[v]);
  }

  void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
      if (ranks[a] < ranks[b])
        swap(a, b);
      parents[b] = a;
      ranks[a] += ranks[b];
    }
  }
};