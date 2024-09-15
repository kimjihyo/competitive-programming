#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ans[arr[0]] = 1;
  for (int i = 1; i < n; i++) {
    int index = 0;
    for (int j = 0; j < n; j++) {
      if (ans[j] == 0) {
        if (index++ == arr[i]) {
          ans[j] = i + 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}