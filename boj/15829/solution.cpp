#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int l;
  string str;
  cin >> l;
  cin >> str;
  long long sum = 0;
  for (int i = str.size() - 1; i > -1; i--) {
    long long n = str[i] - 'a' + 1;
    sum *= 31;
    sum += n;
    sum %= 1234567891;
  }
  cout << sum << '\n';
  return 0;
}