#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> arr;
int memo[500][500]{};

int calc(int from, int to) {
  if (from == to)
    return 0;
  if (memo[from][to] != 0)
    return memo[from][to];
  if (to - from == 1)
    return arr[from].first * arr[from].second * arr[to].second;
  int result = INT_MAX;
  for (int i = from; i < to; i++) {
    int a = calc(from, i);
    int b = calc(i + 1, to);
    int c = arr[from].first * arr[i].second * arr[to].second;
    int tmp = a + b + c;
    if (result > tmp)
      result = tmp;
  }
  memo[from][to] = result;
  return result;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.push_back({x, y});
  }
  cout << calc(0, n - 1) << '\n';
  return 0;
}