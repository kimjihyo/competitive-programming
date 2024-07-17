#include <cmath>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

vector<string> ans;
void solution(int a, int b) {
  bool visited[10001]{};
  queue<pair<int, string>> q;
  q.push({a, ""});
  visited[a] = true;
  while (!q.empty()) {
    auto n = q.front();
    q.pop();
    if (n.first == b) {
      ans.push_back(n.second);
      return;
    }
    int val = n.first;
    int v = (val*2)%10000;
    if (!visited[v]) {
      visited[v] = true;
      q.push({v, n.second + "D"});
    }
    v =val - 1 < 0 ? 9999 : val - 1; 
    if (!visited[v]) {
      visited[v] = true;
      q.push({v, n.second + "S"});
    }
    v = (val % 1000) * 10 + (val / 1000);
    if (!visited[v]) {
      visited[v] = true;
      q.push({v, n.second + "L"});
    }
    v = val / 10 + (val % 10) * 1000; 
    if (!visited[v]) {
      visited[v] = true;
      q.push({v, n.second + "R"});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    solution(a, b);
  }
  for (auto s : ans) {
    cout << s << '\n';
  }
}