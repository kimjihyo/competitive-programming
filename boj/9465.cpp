#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int z = 0; z < t; z++) {
    int n;
    cin >> n;
    vector<int> arr[2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        int val;
        cin >> val;
        arr[i].push_back(val);
      }
    }
    for (int k = 1; k < n; k++) {
      arr[0][k] = max(arr[1][k - 1] + arr[0][k], arr[0][k - 1]);
      arr[1][k] = max(arr[0][k - 1] + arr[1][k], arr[1][k - 1]);
    }
    cout << max(arr[0][n - 1], arr[1][n - 1]) << '\n';
  }
  return 0;
}