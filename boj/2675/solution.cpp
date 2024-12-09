#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    string str;
    cin >> n >> str;
    for (char c : str) {
      for (int i = 0; i < n; i++) {
        cout << c;
      }
    }
    cout << '\n';
  }
  return 0;
}
