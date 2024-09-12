#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct compare {
  bool operator()(pair<char, int> &a, pair<char, int> &b) {
    return a.first > b.first;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str, ans;
  cin >> str;
  unordered_map<char, int> dict;
  ans.resize(str.size());
  for (auto c : str) {
    auto it = dict.find(c);
    if (it == dict.end()) {
      dict.insert({c, 1});
    } else {
      it->second++;
    }
  }
  int numberOfOdd = 0;
  priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
  for (auto p : dict) {
    pq.push(p);
    if (p.second % 2 != 0) {
      numberOfOdd++;
    }
  }
  if (numberOfOdd != 0 && numberOfOdd != 1) {
    cout << "I'm Sorry Hansoo\n";
    return 0;
  }
  int idx = 0;
  while (!pq.empty()) {
    auto p = pq.top();
    if (p.second == 1) {
      ans[ans.size() / 2] = p.first;
    } else {
      if (p.second % 2 != 0) {
        ans[ans.size() / 2] = p.first;
        p.second--;
      }
      for (int i = 0; i < p.second / 2; i++) {
        ans[idx + i] = p.first;
        ans[ans.size() - 1 - i - idx] = p.first;
      }
      idx += p.second / 2;
    }
    pq.pop();
  }
  cout << ans << '\n';
  return 0;
}