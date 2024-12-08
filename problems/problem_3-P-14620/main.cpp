#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

struct Point {
  int y, x;
};

int max_length;
vector<vector<int>> input_map;
vector<vector<int>> visited;
int result = INT_MAX;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int calculate_cost(Point p) {
  int cost = input_map[p.y][p.x];
  for (int i = 0; i < 4; i++) {
    int ny = p.y + dy[i];
    int nx = p.x + dx[i];
    cost += input_map[ny][nx];
  }
  return cost;
}

bool can_place_flower(Point p) {
  if (visited[p.y][p.x])
    return false;
  for (int i = 0; i < 4; i++) {
    int ny = p.y + dy[i];
    int nx = p.x + dx[i];
    if (ny < 0 || ny >= max_length || nx < 0 || nx >= max_length ||
        visited[ny][nx]) {
      return false;
    }
  }
  return true;
}

void place_flower(Point p, bool place) {
  visited[p.y][p.x] = place;
  for (int i = 0; i < 4; i++) {
    int ny = p.y + dy[i];
    int nx = p.x + dx[i];
    visited[ny][nx] = place;
  }
}

void dfs(int level, int acc_cost) {
  if (level == 3) {
    result = min(result, acc_cost);
    return;
  }

  for (int y = 1; y < max_length - 1; y++) {
    for (int x = 1; x < max_length - 1; x++) {
      Point p = {y, x};
      if (can_place_flower(p)) {
        int cost = calculate_cost(p);
        place_flower(p, true);
        dfs(level + 1, acc_cost + cost);
        place_flower(p, false);
      }
    }
  }
}

int main() {
  cin >> max_length;
  input_map = vector<vector<int>>(max_length, vector<int>(max_length));
  visited = vector<vector<int>>(max_length, vector<int>(max_length, 0));

  for (int i = 0; i < max_length; i++) {
    for (int j = 0; j < max_length; j++) {
      cin >> input_map[i][j];
    }
  }

  dfs(0, 0);
  cout << result << endl;

  return 0;
}
