#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

bool zeroOrDifferentSigns(ll a, ll b) {
  if (a == 0 || b == 0)
    return true;
  if (a > 0 && b < 0)
    return true;
  if (a < 0 && b > 0)
    return true;
  return false;
}

ll ccw(pair<ll, ll> &p0, pair<ll, ll> &p1, pair<ll, ll> &p2) {
  return (p1.first - p0.first) * (p2.second - p0.second) -
         (p1.second - p0.second) * (p2.first - p0.first);
}

int main() {
  pair<ll, ll> a, b, c, d;
  cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >>
      d.first >> d.second;
  ll abc, abd, cda, cdb;
  bool intersecting;
  abc = ccw(a, b, c);
  abd = ccw(a, b, d);
  cda = ccw(c, d, a);
  cdb = ccw(c, d, b);

  // cout << abc << ' ' << abd << ' ' << cda << ' ' << cdb << '\n';

  if (abc == 0 && abd == 0 && cda == 0 && cdb == 0) {
    if (a > b) {
      swap(a, b);
    }
    if (c > d) {
      swap(c, d);
    }
    if (c < a) {
      swap(a, c);
      swap(b, d);
    }
    // cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second
    //      << '\n';
    // cout << c.first << ' ' << c.second << ' ' << d.first << ' ' << d.second
    //      << '\n';
    intersecting = b >= c && b <= d || c >= a && c <= b;
  } else {
    intersecting =
        zeroOrDifferentSigns(abc, abd) && zeroOrDifferentSigns(cda, cdb);
  }
  cout << intersecting << '\n';
  return 0;
}