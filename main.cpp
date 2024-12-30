#include <iostream>
using namespace std;
int main() {
  int arr[202]{};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr[val + 100]++;
  }
  int r;
  cin >> r;
  cout << arr[r + 100] << '\n';
  return 0;
}
