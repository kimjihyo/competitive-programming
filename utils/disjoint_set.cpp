#include <vector>

struct DisjointSet {
  std::vector<int> parents;
  std::vector<int> ranks;

  DisjointSet(int maxSize) {
    parents.resize(maxSize);
    ranks.resize(maxSize);
    for (int i = 0; i < maxSize; i++) {
      parents[i] = i;
      ranks[i] = 1;
    }
  }

  int find_set(int v) {
    if (v == parents[v])
      return v;
    return parents[v] = find_set(parents[v]);
  }

  void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (ranks[a] < ranks[b])
        std::swap(a, b);
      parents[b] = a;
      ranks[a] += ranks[b];
    }
  }
};