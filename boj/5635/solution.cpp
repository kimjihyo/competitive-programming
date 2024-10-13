#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct bd {
  string name;
  int year;
  int month;
  int day;
};

bool compare(bd &a, bd &b) {
  if (a.year != b.year) {
    return a.year < b.year;
  }
  if (a.month != b.month) {
    return a.month < b.month;
  }
  return a.day < b.day;
}

int main() {
  int n;
  cin >> n;
  vector<bd> arr;

  for (int i = 0; i < n; i++) {
    string name;
    int year, month, day;
    cin >> name >> year >> month >> day;
    arr.push_back({name, day, month, year});
  }
  sort(arr.begin(), arr.end(), compare);
  cout << arr[arr.size() - 1].name << '\n' << arr[0].name << '\n';

  return 0;
}