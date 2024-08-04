#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool isNumeric(string &str) {
  for (auto c : str) {
    char t = c - '0';
    if (t > -1 && t < 10)
      continue;
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> numToName(n + 1);
  unordered_map<string, int> nameToNum;
  for (int i = 1; i < n + 1; i++) {
    string name;
    cin >> name;
    numToName[i] = name;
    nameToNum.insert({name, i});
  }
  for (int i = 0; i < m; i++) {
    string query;
    cin >> query;
    if (isNumeric(query)) {
      cout << numToName[stoi(query)] << '\n';
    } else {
      auto it = nameToNum.find(query);
      if (it != nameToNum.end()) {
        cout << nameToNum.find(query)->second << '\n';
      }
    }
  }
  return 0;
}