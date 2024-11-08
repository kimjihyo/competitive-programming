#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    pair<int, int> from, to;
    cin >> from.first >> from.second >> to.first >> to.second;

    int sum = 0;
    for (int j = from.first - 1; j < to.first; j++) {
      for (int k = from.second - 1; k < to.second; k++) {
        sum += arr[j][k];
      }
    }
    cout << sum << '\n';
  }
  return 0;
}
