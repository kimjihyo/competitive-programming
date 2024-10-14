#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  int sum = 64;
  arr.push_back(64);

  while (sum != n) {
    int a = arr.back() / 2;
    arr.pop_back();
    if (sum - a >= n) {
      sum -= a;
      arr.push_back(a);
    } else {
      arr.push_back(a);
      arr.push_back(a);
    }
  }
  cout << arr.size() << '\n';
  return 0;
}