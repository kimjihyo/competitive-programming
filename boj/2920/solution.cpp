#include <iostream>
using namespace std;

int main() {
  int prevValue;
  cin >> prevValue;
  bool decreasing = false;
  bool increasing = false;
  for (int i = 0; i < 7; i++) {
    int value;
    cin >> value;
    if (value > prevValue) {
      increasing = true;
    } else if (value < prevValue) {
      decreasing = true;
    }
    prevValue = value;
  }
  if (increasing && decreasing) {
    cout << "mixed\n";
  } else if (increasing) {
    cout << "ascending\n";
  } else {
    cout << "descending\n";
  }
  return 0;
}
