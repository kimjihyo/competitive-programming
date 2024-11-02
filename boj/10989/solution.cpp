#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> memo(10'001, 0);

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    memo[value]++;
  }

  for (int i = 1; i < 10'001; i++) {
    for (int j = 0; j < memo[i]; j++) {
      cout << i << '\n';
    }
  }

  return 0;
}
