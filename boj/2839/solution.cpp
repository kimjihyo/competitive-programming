#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n + 1, -1);
  arr[3] = 1;
  arr[5] = 1;

  for (int i = 6; i < n + 1; i++) {
    int three = arr[i - 3];
    int five = arr[i - 5];
    if (three != -1 && five == -1) {
      arr[i] = three + 1;
    } else if (three == -1 && five != -1) {
      arr[i] = five + 1;
    } else if (three == -1 && five == -1) {
      arr[i] = -1;
    } else if (three > five) {
      arr[i] = five + 1;
    } else if (three < five) {
      arr[i] = three + 1;
    } else {
      arr[i] = five + 1;
    }
  }

  cout << arr[n] << '\n';
}