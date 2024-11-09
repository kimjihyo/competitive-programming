#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string line;
  while (getline(cin, line)) {
    int a, b;
    a = line[0] - '0';
    b = line[2] - '0';
    cout << a + b << '\n';
  }
  return 0;
}
