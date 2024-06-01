#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int arr[1025][1025]{};

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      int val;
      cin >> val;
      arr[i][j] = arr[i][j - 1] + val;
    }
  }

  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int sum = 0;
    for (int j = x1; j < x2 + 1; j++) {
      sum += arr[j][y2] - arr[j][y1 - 1];
    }
    cout << sum << '\n';
  }
  return 0;
}