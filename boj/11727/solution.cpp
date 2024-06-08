#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr;
  arr.push_back(0);
  arr.push_back(1);
  arr.push_back(3);

  int n;
  cin >> n;

  for (int i = 3; i < n + 1; i++) {
    arr.push_back((arr[i - 1] + arr[i - 2] + arr[i - 2]) % 10007);
  }
  cout << arr[n] << '\n';

  return 0;
}