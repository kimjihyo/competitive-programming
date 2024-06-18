#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> arr;
  int n, m;
  cin >> n >> m;
  arr.push_back(0);
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr.push_back(arr[i] + val);
  }

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    cout << arr[to] - arr[from - 1] << '\n';
  }
  return 0;
}