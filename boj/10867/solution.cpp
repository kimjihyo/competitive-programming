#include <iostream>
using namespace std;

int main() {
  bool arr[2002]{};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr[val + 1000] = true;
  }
  for (int i = 0; i < 2002; i++) {
    if (arr[i]) {
      cout << i - 1000 << ' ';
    }
  }
  cout << '\n';
  return 0;
}
