#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> priorities;

bool compare(int a, int b) { return priorities[a] > priorities[b]; }

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr;
  priorities.resize(n + 1);
  for (int i = 0; i < n; i++) {
    arr.push_back(i + 1);
    priorities[i + 1] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (priorities[a] == 0 && priorities[b] == 0) {
      priorities[a] = 2;
      priorities[b] = 1;
    } else if (priorities[a] == 0) {
      priorities[a] = priorities[b] + 1;
    } else if (priorities[b] == 0) {
      priorities[b] = priorities[a] - 1;
    } else {
      priorities[a] = priorities[b] + 1;
    }
  }
  sort(arr.begin(), arr.end(), compare);
  for (auto a : arr) {
    cout << a << ' ';
  }
  cout << '\n';
  return 0;
}