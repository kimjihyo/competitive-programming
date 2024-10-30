#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int scenario = 1;
  while (true) {
    int n;
    cin >> n;
    cin.ignore();
    if (n == 0) {
      break;
    }
    vector<string> names(n);
    vector<bool> impounded(n, false);
    for (int i = 0; i < n; i++) {
      getline(cin, names[i]);
    }
    for (int i = 0; i < n * 2 - 1; i++) {
      int a;
      char b;
      cin >> a >> b;
      impounded[a - 1] = !impounded[a - 1];
    }
    for (int i = 0; i < n; i++) {
      if (impounded[i]) {
        cout << scenario << ' ' << names[i] << '\n';
      }
    }
    scenario++;
  }

  return 0;
}
