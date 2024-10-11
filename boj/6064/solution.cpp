#include <iostream>
using namespace std;

int calc(int m, int n, int x, int y) {
  int i = 0;
  int k = 0;
  while (k < m * n) {
    k = i++ * m + x;
    if ((k - y) % n == 0) {
      return k;
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    cout << calc(m,n,x,y) << '\n';
  }
  return 0;
}
