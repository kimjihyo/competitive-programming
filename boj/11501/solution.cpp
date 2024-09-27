#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sellAmount = 0;
    long long buyAmount = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        sellAmount += arr[i] * num;
        num = 0;
      } else {
        buyAmount += arr[i];
        num++;
      }
    }
    sellAmount += arr[n - 1] * num;
    cout << sellAmount - buyAmount << '\n';
  }
  return 0;
}