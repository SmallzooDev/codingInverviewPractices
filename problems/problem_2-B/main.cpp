#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int cases, n, m, k;
vector<vector<int>> input_map;
vector<vector<int>> visited_map;
vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

void dfs(int x, int y) {
  if (visited_map[y][x] || input_map[y][x] == 0)
    return;

  visited_map[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int next_y = y + dy[i];
    int next_x = x + dx[i];

    if (next_y < 0 || next_x < 0 || next_x >= m || next_y >= n)
      continue;

    dfs(next_x, next_y);
  }
}

int main() {
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    cin >> m >> n >> k;

    visited_map = vector<vector<int>>(n, vector<int>(m, 0));
    input_map = vector<vector<int>>(n, vector<int>(m, 0));
    int count = 0;

    for (int j = 0; j < k; j++) {
      int temp_x, temp_y;
      cin >> temp_x >> temp_y;
      input_map[temp_y][temp_x] = 1;
    }

    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        if (input_map[y][x] == 1 && !visited_map[y][x]) {
          count++;
          dfs(x, y);
        }
      }
    }

    cout << count << endl;
  }

  return 0;
}
