#include <iostream>
#include <vector>
using namespace std;

int r, c, t;

pair<int, int> ac_pos_up = {-1, -1};
pair<int, int> ac_pos_down = {-1, -1};

vector<vector<int>> state;

void print_state() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << state[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

void copy_state(vector<vector<int>> &from, vector<vector<int>> &to) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      to[i][j] = from[i][j];
    }
  }
}

bool is_within_boundary(pair<int, int> &pos) {
  return pos.first > -1 && pos.first < r && pos.second > -1 && pos.second < c;
}

void disperse(vector<vector<int>> &next_state, int y, int x) {
  int cnt = 0;
  pair<int, int> dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (auto dir : dirs) {
    pair<int, int> pos = {y + dir.first, x + dir.second};
    if (is_within_boundary(pos) && state[pos.first][pos.second] != -1) {
      next_state[pos.first][pos.second] += state[y][x] / 5;
      cnt++;
    }
  }
  next_state[y][x] -= state[y][x] / 5 * cnt;
}

void circulate() {
  // up
  // to right
  int prev_value = state[ac_pos_up.first][ac_pos_up.second + 1];
  state[ac_pos_up.first][ac_pos_up.second + 1] = 0;
  for (int i = ac_pos_up.second + 2; i < c; i++) {
    int cur_value = state[ac_pos_up.first][i];
    state[ac_pos_up.first][i] = prev_value;
    prev_value = cur_value;
  }
  // to up
  for (int i = ac_pos_up.first - 1; i > -1; i--) {
    int cur_value = state[i][c - 1];
    state[i][c - 1] = prev_value;
    prev_value = cur_value;
  }

  // to left
  for (int i = c - 2; i > -1; i--) {
    int cur_value = state[0][i];
    state[0][i] = prev_value;
    prev_value = cur_value;
  }

  // to down
  for (int i = 1; i < ac_pos_up.first; i++) {
    int cur_value = state[i][0];
    state[i][0] = prev_value;
    prev_value = cur_value;
  }

  // down
  // to right
  prev_value = state[ac_pos_down.first][ac_pos_down.second + 1];
  state[ac_pos_down.first][ac_pos_down.second + 1] = 0;
  for (int i = ac_pos_down.second + 2; i < c; i++) {
    int cur_value = state[ac_pos_down.first][i];
    state[ac_pos_down.first][i] = prev_value;
    prev_value = cur_value;
  }
  // to down
  for (int i = ac_pos_down.first + 1; i < r; i++) {
    int cur_value = state[i][c - 1];
    state[i][c - 1] = prev_value;
    prev_value = cur_value;
  }
  // to left
  for (int i = c - 2; i > -1; i--) {
    int cur_value = state[r - 1][i];
    state[r - 1][i] = prev_value;
    prev_value = cur_value;
  }
  // to up
  for (int i = r - 2; i > ac_pos_down.first; i--) {
    int cur_value = state[i][0];
    state[i][0] = prev_value;
    prev_value = cur_value;
  }
}

void simulate() {
  vector<vector<int>> next_state(r, vector<int>(c));
  copy_state(state, next_state);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (state[i][j] != -1) {
        disperse(next_state, i, j);
      }
    }
  }

  copy_state(next_state, state);
  circulate();
}

int main() {
  cin >> r >> c >> t;
  state.resize(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> state[i][j];
      if (state[i][j] == -1) {
        if (ac_pos_up.first == -1) {
          ac_pos_up.first = i;
          ac_pos_up.second = j;
        } else {
          ac_pos_down.first = i;
          ac_pos_down.second = j;
        }
      }
    }
  }
  for (int i = 0; i < t; i++) {
    simulate();
  }

  int sum = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (state[i][j] != -1) {
        sum += state[i][j];
      }
    }
  }
  cout << sum << '\n';
  return 0;
}
