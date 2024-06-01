#include <iostream>
using namespace std;

int k;
bool selected[13]{};
int nums[13]{};

void combination(int idx, int cnt) {
  if (cnt == 6) {
    for (int i = 0; i < k; i++) {
      if (selected[i]) {
        cout << nums[i] << ' ';
      }
    }
    cout << '\n';
    return;
  }

  for (int i = idx; i < k; i++) {
    selected[i] = true;
    combination(i + 1, cnt + 1);
    selected[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> k;
    if (k == 0)
      break;
    for (int i = 0; i < k; i++) {
      cin >> nums[i];
    }
    combination(0, 0);
    cout << '\n';
  }
  return 0;
}