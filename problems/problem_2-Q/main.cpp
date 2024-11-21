#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
vector<vector<int>> input_map;
vector<vector<int>> visited_map;
int cheese_count = 0;

void mark_outer_air(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  visited_map[y][x] = 1;

  while (!q.empty()) {
    auto [current_y, current_x] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int next_y = current_y + dy[i];
      int next_x = current_x + dx[i];

      if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
        continue;

      if (visited_map[next_y][next_x] || input_map[next_y][next_x] == 1)
        continue;

      visited_map[next_y][next_x] = 1;
      q.push({next_y, next_x});
    }
  }
}

int main() {
  cin >> n >> m;
  input_map = vector<vector<int>>(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> input_map[i][j];
      if (input_map[i][j] == 1)
        cheese_count++;
    }
  }

  int result_count = 0;
  int result_last = 0;

  while (cheese_count > 0) {
    visited_map = vector<vector<int>>(n, vector<int>(m, 0));
    mark_outer_air(0, 0);

    vector<pair<int, int>> remove_list;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (input_map[i][j] == 1) {
          for (int k = 0; k < 4; k++) {
            int next_y = i + dy[k];
            int next_x = j + dx[k];
            if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
              continue;
            if (visited_map[next_y][next_x] == 1) {
              remove_list.push_back({i, j});
              break;
            }
          }
        }
      }
    }

    result_last = remove_list.size();
    for (auto [y, x] : remove_list) {
      input_map[y][x] = 0;
    }
    cheese_count -= result_last;
    result_count++;
  }

  cout << result_count << '\n';
  cout << result_last << '\n';
  return 0;
}
