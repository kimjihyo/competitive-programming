#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int arr[15][15]{};
  for (int i = 1; i < 15; i++) {
    arr[0][i] = i;
  }
  for (int i = 1; i < 15; i++) {
    for (int j = 1; j < 15; j++) {
      for (int k = 1; k < j + 1; k++) {
        arr[i][j] += arr[i - 1][k];
      }
    }
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int floor, room;
    cin >> floor >> room;
    cout << arr[floor][room] << '\n';
  }

  return 0;
}
