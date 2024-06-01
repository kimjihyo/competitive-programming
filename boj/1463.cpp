#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x;
  cin >> x;
  vector<int> arr(x + 1, INT_MAX);

  arr[1] = 0;
  arr[2] = 1;
  arr[3] = 1;

  for (int i = 4; i < x + 1; i++) {
    int a = arr[i - 1];
    if (i % 2 == 0)
      a = min(a, arr[i / 2]);
    if (i % 3 == 0)
      a = min(a, arr[i / 3]);
    arr[i] = a + 1;
  }

  cout << arr[x] << '\n';

  return 0;
}