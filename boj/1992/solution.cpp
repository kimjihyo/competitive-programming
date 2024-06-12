#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int arr[64][64];
int n;

string func(int y, int x, int size) {

  bool check = true;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (arr[y + i][x + j] != arr[y][x]) {
        check = false;
        break;
      }
    }
  }

  if (check) {
    return to_string(arr[y][x]);
  }

  string r1 = func(y, x, size / 2);
  string r2 = func(y, x + size / 2, size / 2);
  string r3 = func(y + size / 2, x, size / 2);
  string r4 = func(y + size / 2, x + size / 2, size / 2);
  string r = "(" + r1 + r2 + r3 + r4 + ")";

  return r;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++) {
      arr[i][j] = str[j] - '0';
    }
  }

  cout << func(0, 0, n) << '\n';
}