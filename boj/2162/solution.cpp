#include <iostream>
#include <unordered_map>
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

  int findSet(int a) {
    if (a == parents[a])
      return a;
    return parents[a] = findSet(parents[a]);
  }

  void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b)
      return;
    if (ranks[a] > ranks[b])
      swap(a, b);
    parents[a] = b;
    ranks[b] += ranks[a];
  }
};

struct Point {
  int x, y;
  bool operator==(Point &other) { return x == other.x && y == other.y; }
  bool operator>(Point &other) { return x + y > other.x + other.y; }
  bool operator<(Point &other) { return x + y < other.x + other.y; }
  bool operator>=(Point &other) { return *this == other || *this > other; }
  bool operator<=(Point &other) { return *this == other || *this < other; }
};

struct Segment {
  Point p1;
  Point p2;
};

long long ccw(Point p1, Point p2, Point p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool isIntersecting(Segment seg1, Segment seg2) {
  long long check11 = ccw(seg1.p1, seg1.p2, seg2.p1);
  long long check12 = ccw(seg1.p1, seg1.p2, seg2.p2);
  long long check21 = ccw(seg2.p1, seg2.p2, seg1.p1);
  long long check22 = ccw(seg2.p1, seg2.p2, seg1.p2);

  if (check11 == 0 && check12 == 0 && check21 == 0 && check22 == 0) {
    if (seg1.p1 > seg1.p2) {
      swap(seg1.p1, seg1.p2);
    }
    if (seg2.p1 > seg2.p2) {
      swap(seg2.p1, seg2.p1);
    }
    return (seg2.p2 >= seg1.p1 && seg2.p2 <= seg1.p2) ||
           (seg1.p2 >= seg2.p1 && seg1.p2 <= seg2.p2);
  }

  return check11 * check12 <= 0 && check21 * check22 <= 0;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments;
  DisjointSet dset(n);

  for (int i = 0; i < n; i++) {
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    segments.push_back({p1, p2});
  }
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j > -1; j--) {
      if (isIntersecting(segments[i], segments[j])) {
        dset.unionSet(i, j);
      }
    }
  }

  unordered_map<int, int> m;
  int cnt = 0, greatest = 1;
  for (auto p : dset.parents) {
    p = dset.findSet(p);
    auto it = m.find(p);
    if (it != m.end()) {
      it->second++;
      if (greatest < it->second) {
        greatest = it->second;
      }
    } else {
      m.insert({p, 1});
      cnt++;
    }
  }
  cout << cnt << '\n' << greatest << '\n';

  return 0;
}