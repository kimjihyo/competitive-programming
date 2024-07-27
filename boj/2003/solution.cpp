#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr;
  int n, m;
  int ans = 0;
  cin >> n >> m;
  arr.resize(n + 1);
  arr[0] = 0;

  for (int i = 1; i < n + 1; i++) {
    int val;
    cin >> val;
    arr[i] = val + arr[i - 1];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      if (arr[j] - arr[i] == m)
        ans++;
    }
  }
  cout << ans << '\n';
}