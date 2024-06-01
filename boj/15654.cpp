#include <algorithm>
#include <iostream>
using namespace std;

int n, m;

int result[8];
int selected[8]{};
int arr[8];

void permutation(int cnt) {
  if (cnt == m) {
    for (int i = 0; i < cnt; i++) {
      cout << result[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!selected[i]) {
      selected[i] = true;
      result[cnt] = arr[i];
      permutation(cnt + 1);
      selected[i] = false;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  permutation(0);
  return 0;
}