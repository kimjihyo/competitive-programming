#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(5));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }

  int cnt = -1;
  int ans = -1;

  for (int i = 0; i < n; i++) {
    vector<bool> check(n, false);
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 5; k++) {
        if (i != j && arr[i][k] == arr[j][k]) {
          check[j] = true;
        }
      }
    }
    int _cnt = 0;
    for (int j = 0; j < n; j++) {
      if (check[j]) {
        _cnt++;
      }
    }
    if (_cnt > cnt) {
      cnt = _cnt;
      ans = i;
    }
  }
  cout << ans + 1 << '\n';

  return 0;
}
