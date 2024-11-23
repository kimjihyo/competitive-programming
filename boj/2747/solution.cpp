#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> arr(n + 1);
  arr[0] = 0;
  arr[1] = 1;

  for (int i = 2; i < n + 1; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  cout << arr[n] << '\n';

  return 0;
}
