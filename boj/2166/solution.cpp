#include <ios>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  long double x, y;
};

long double ccw(Point p1, Point p2, Point p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int main() {
  int n;
  vector<Point> points;
  cin >> n;
  Point origin;
  long double area = 0;

  for (int i = 0; i < n; i++) {
    long double x, y;
    cin >> x >> y;
    points.push_back({x, y});

    if (i > 1) {
      area += ccw(points[0], points[i - 1], points[i]) / 2;
    }
  }

  cout << fixed;
  cout.precision(1);
  cout << abs(area) << '\n';

  return 0;
}