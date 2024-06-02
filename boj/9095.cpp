#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr;
  arr.push_back(0);
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(4);
  for (int i = 0; i < n; i++) {
    int val, cur;
    cin >> val;
    cur = arr.size() - 1;
    if (arr.size() > val)
      cout << arr[val] << '\n';
    else {
      while (cur < val) {
        arr.push_back(arr[cur] + arr[cur - 1] + arr[cur - 2]);
        cur++;
      }
      cout << arr[cur] << '\n';
    }
  }
  return 0;
}