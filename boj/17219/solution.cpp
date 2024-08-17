#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, string> memo;
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string site, pw;
    cin >> site >> pw;
    memo.insert({site, pw});
  }

  for (int i = 0; i < m; i++) {
    string query;
    cin >> query;
    cout << memo.find(query)->second << '\n';
  }

  return 0;
}