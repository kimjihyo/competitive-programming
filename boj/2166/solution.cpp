#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  long long x, y;
};

long long ccw(Point p1, Point p2, Point p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int main() {
  int n;
  vector<Point> points;
  cin >> n;
  Point origin;
  long long area = 0;

  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    points.push_back({x, y});

    if (i > 1) {
      area += ccw(points[0], points[i - 1], points[i]);
    }
  }

  // cout << round(10 * area) / 10 << '\n';
  // cout.precision(1);
  // cout << abs(area) << '\n';
  if (area % 2 == 1) {
    cout << abs(area / 2) << ".5\n";
  } else {
    cout << abs(area / 2) << '\n';
  }

  return 0;
}