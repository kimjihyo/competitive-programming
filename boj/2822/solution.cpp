#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second > b.second;
}

int main() {
  pair<int, int> arr[8];
  for (int i = 0; i < 8; i++) {
    arr[i].first = i;
    cin >> arr[i].second;
  }

  sort(arr, arr + 8, compare);

  int sum = 0;
  int orders[5];
  for (int i = 0; i < 5; i++) {
    sum += arr[i].second;
    orders[i] = arr[i].first;
  }

  sort(orders, orders + 5);

  cout << sum << '\n';
  for (int i = 0; i < 5; i++) {
    cout << orders[i] + 1 << ' ';
  }
  cout << '\n';
  return 0;
}
