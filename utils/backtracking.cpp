#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<int> result;

void print_result() {
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ' ';
  }
  cout << '\n';
}

void combination(int n, int r, int cnt, int idx) {
  if (r == cnt) {
    print_result();
    return;
  }

  for (int i = idx; i < n; i++) {
    result[cnt] = i;
    combination(n, r, cnt + 1, i + 1);
  }
}

void permutation(int n, int r, int cnt) {
  if (r == cnt) {
    print_result();
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      result[cnt] = i;
      permutation(n, r, cnt + 1);
      visited[i] = false;
    }
  }
}

void combination_with_repetition(int n, int r, int cnt, int idx) {
  if (cnt == r) {
    print_result();
    return;
  }
  for (int i = idx; i < n; i++) {
    result[cnt] = i;
    combination_with_repetition(n, r, cnt + 1, i);
  }
}

void permutation_with_repetition(int n, int r, int cnt) {
  if (cnt == r) {
    print_result();
    return;
  }
  for (int i = 0; i < n; i++) {
    result[cnt] = i;
    permutation_with_repetition(n, r, cnt + 1);
  }
}

int main() {
  int n, r;
  cin >> n >> r;
  visited.resize(n);
  result.resize(r);
  fill(visited.begin(), visited.end(), false);
  // combination(n, r, 0, 0);
  // permutation(n, r,0);
  // combination_with_repetition(n, r, 0, 0);
  permutation_with_repetition(n, r, 0);

  return 0;
}