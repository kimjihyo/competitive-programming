#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  pair<int, int> arr[41];

  arr[0] = {1, 0};
  arr[1] = {0, 1};
  for (int i = 2; i < 41; i++) {
    arr[i] = {
        arr[i - 1].first + arr[i - 2].first,
        arr[i - 1].second + arr[i - 2].second,
    };
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << arr[n].first << ' ' << arr[n].second << '\n';
  }
  return 0;
}