#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

struct Point {
  int y, x;
};

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<char>> board;
vector<vector<int>> visited;
int max_y, max_x, result = 0;

bool is_out_of_bound(Point p) {
  return (p.y < 0 || p.x < 0 || p.y >= max_y || p.x >= max_x);
}

void dfs(Point current, int path_mask, int depth) {
  int y = current.y, x = current.x;

  if (is_out_of_bound(current) || visited[y][x]) {
    return;
  }

  int char_bit = 1 << (board[y][x] - 'A');
  if (path_mask & char_bit) {
    result = max(result, depth - 1);
    return;
  }

  visited[y][x] = 1;
  path_mask |= char_bit;
  result = max(result, depth);

  for (int i = 0; i < 4; i++) {
    int next_y = y + dy[i], next_x = x + dx[i];
    dfs({next_y, next_x}, path_mask, depth + 1);
  }

  visited[y][x] = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> max_y >> max_x;
  board.assign(max_y, vector<char>(max_x));
  visited.assign(max_y, vector<int>(max_x, 0));

  for (int i = 0; i < max_y; i++) {
    for (int j = 0; j < max_x; j++) {
      cin >> board[i][j];
    }
  }

  dfs({0, 0}, 0, 1);
  cout << result - 1 << endl;

  return 0;
}
