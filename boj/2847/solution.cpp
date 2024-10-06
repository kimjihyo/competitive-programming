#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int prevScore = arr[n - 1];
  int ans = 0;
  for (int i = n - 2; i > -1; i--) {
    if (arr[i] >= prevScore) {
      ans += arr[i] - prevScore + 1;
      prevScore = prevScore - 1;
    } else {
      prevScore = arr[i];
    }
  }
  cout << ans << '\n';
  return 0;
}
