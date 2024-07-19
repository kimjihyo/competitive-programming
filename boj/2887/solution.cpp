#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct vec3 {
  int id, x, y, z;
};

struct edge {
  int u, v, w;
};

int getDistance(vec3 &a, vec3 &b) {
  int x = abs(a.x - b.x);
  int y = abs(a.y - b.y);
  int z = abs(a.z - b.z);
  return min(min(x, y), z);
}

bool compEdge(edge &a, edge &b) { return a.w < b.w; }

bool compx(vec3 &a, vec3 &b) { return a.x < b.x; }

bool compy(vec3 &a, vec3 &b) { return a.y < b.y; }

bool compz(vec3 &a, vec3 &b) { return a.z < b.z; }

vector<edge> edges;
vector<vec3> planets;
vector<int> parents;
vector<int> ranks;

void init(int maxSize) {
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

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    planets.push_back({i, x, y, z});
  }
  sort(planets.begin(), planets.end(), compx);
  for (int i = 0; i < n - 1; i++) {
    auto here = planets[i];
    auto there = planets[i + 1];
    edges.push_back({here.id, there.id, getDistance(here, there)});
  }
  sort(planets.begin(), planets.end(), compy);
  for (int i = 0; i < n - 1; i++) {
    auto here = planets[i];
    auto there = planets[i + 1];
    edges.push_back({here.id, there.id, getDistance(here, there)});
  }
  sort(planets.begin(), planets.end(), compz);
  for (int i = 0; i < n - 1; i++) {
    auto here = planets[i];
    auto there = planets[i + 1];
    edges.push_back({here.id, there.id, getDistance(here, there)});
  }
  init(n);
  sort(edges.begin(), edges.end(), compEdge);
  int cost = 0;
  for (auto edge : edges) {
    int rootU = find_set(edge.u);
    int rootV = find_set(edge.v);
    if (rootU != rootV) {
      cost += edge.w;
      union_set(edge.u, edge.v);
    }
  }
  cout << cost << '\n';
  return 0;
}