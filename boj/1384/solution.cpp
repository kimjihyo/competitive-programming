#include <iostream>
#include <vector>
using namespace std;

int main() {
  int idx = 1;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }

    vector<string> names(n);
    vector<pair<int, int>> memos;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        string input;
        cin >> input;
        if (j == 0) {
          names[i] = input;
        } else {
          if (input == "N") {
            int idx = i - j;
            if (idx < 0) {
              idx = n + idx;
            }
            memos.push_back({idx, i});
          }
        }
      }
    }

    if (idx > 1)
      cout << '\n';
    cout << "Group " << idx++ << '\n';
    if (memos.empty()) {
      cout << "Nobody was nasty\n";
    }

    for (auto p : memos) {
      cout << names[p.first] << " was nasty about " << names[p.second] << '\n';
    }
  }
  return 0;
}
