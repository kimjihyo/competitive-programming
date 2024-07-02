#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> arr;
  string str;
  cin >> str;
  for (auto c : str) {
    arr.push_back(c - '0');
  }
  sort(arr.rbegin(), arr.rend());
  for (auto a : arr) {
    cout << a;
  }
  cout << '\n';
  return 0;
}