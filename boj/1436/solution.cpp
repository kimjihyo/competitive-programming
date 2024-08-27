#include <iostream>
using namespace std;

bool isNumberOfTheBeast(int num) {
  int check = 0;
  while (num > 0) {
    if (num % 10 == 6) {
      check++;
    } else {
      check = 0;
    }
    if (check == 3) {
      return true;
    }
    num /= 10;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  int check = 1;
  int num = 667;
  while (check < n) {
    if (isNumberOfTheBeast(num)) {
      check++;
    }
    num++;
  }
  cout << num - 1 << '\n';
}