#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, largest = INT_MIN;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }

  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (double)arr[i] / largest * 100;
  }
  cout << sum / n << '\n';
  return 0;
}
