#include <iostream>
#include <list>
#include <stack>
using namespace std;

struct m {
  int y, x, state;
};

const int HORIZONTAL = 0;
const int VERTICAL = 1;
const int DIAGNOAL = 2;

int n;
int world[16][16];
bool visited[16][16][3]{};
list<m> moves[4];

int search() {
  int ans = 0;
  stack<m> s;
  s.push({0, 1, HORIZONTAL});
  while (!s.empty()) {
    auto here = s.top();
    s.pop();
    if (here.y == n - 1 && here.x == n - 1) {
      ans++;
      continue;
    }
    for (auto mov : moves[here.state]) {
      m there;
      there.y = here.y + mov.y;
      there.x = here.x + mov.x;
      there.state = mov.state;
      if (there.y < n && there.x < n && there.y > -1 && there.x > -1) {
        if (world[there.y][there.x] != 1 && world[there.y][here.x] != 1 &&
            world[here.y][there.x] != 1) {
          s.push(there);
        }
      }
    }
  }
  return ans;
}

int main() {
  // Initialize moves
  moves[HORIZONTAL].push_back({0, 1, HORIZONTAL});
  moves[HORIZONTAL].push_back({1, 1, DIAGNOAL});
  moves[VERTICAL].push_back({1, 0, VERTICAL});
  moves[VERTICAL].push_back({1, 1, DIAGNOAL});
  moves[DIAGNOAL].push_back({0, 1, HORIZONTAL});
  moves[DIAGNOAL].push_back({1, 0, VERTICAL});
  moves[DIAGNOAL].push_back({1, 1, DIAGNOAL});

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> world[i][j];
    }
  }
  cout << search() << '\n';
  return 0;
}