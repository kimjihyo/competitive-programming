#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(tuple<int, string, int> &a, tuple<int, string, int> &b) {
  if (get<0>(a) == get<0>(b)) {
    return get<2>(a) < get<2>(b);
  }
  return get<0>(a) < get<0>(b);
}

int main() {
  int n;
  cin >> n;

  vector<tuple<int, string, int>> arr;

  for (int i = 0; i < n; i++) {
    int age;
    string name;
    cin >> age >> name;
    arr.push_back({age, name, i});
  }
  sort(arr.begin(), arr.end(), compare);
  for (auto e : arr) {
    cout << get<0>(e) << ' ' << get<1>(e) << '\n';
  }
  return 0;
}