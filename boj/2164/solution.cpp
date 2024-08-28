#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void func() {
  q.pop();
  int num = q.front();
  q.pop();
  q.push(num);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    q.push(i + 1);
  }
  while (q.size() > 1) {
    func();
  }
  cout << q.front() << '\n';
  return 0;
}