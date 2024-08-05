#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;
    arr.push_back({w, h});
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i != j && arr[j].first > arr[i].first &&
          arr[j].second > arr[i].second) {
        cnt++;
      }
    }
    cout << cnt + 1 << ' ';
  }
  cout << '\n';

  return 0;
}