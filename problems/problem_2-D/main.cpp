#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input_map;
vector<vector<int>> visited;
vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

int n, m, k;
vector<int> result_vector;

int dfs(int y, int x) {
  if (visited[y][x] || input_map[y][x])
    return 0;

  visited[y][x] = 1;
  int area = 1;

  for (int i = 0; i < 4; i++) {
    int next_y = y + dy[i];
    int next_x = x + dx[i];

    if (next_y >= 0 && next_x >= 0 && next_y < m && next_x < n)
      area += dfs(next_y, next_x);
  }

  return area;
}

int main() {
  cin >> m >> n >> k;

  input_map = vector<vector<int>>(m, vector<int>(n, 0));
  visited = vector<vector<int>>(m, vector<int>(n, 0));

  for (int l = 0; l < k; l++) {
    int bottom_x, bottom_y, top_x, top_y;
    cin >> bottom_x >> bottom_y >> top_x >> top_y;

    for (int i = bottom_y; i < top_y; i++) {
      for (int j = bottom_x; j < top_x; j++) {
        input_map[i][j] = 1;
      }
    }
  }

  int result = 0;
  for (int y = 0; y < m; y++) {
    for (int x = 0; x < n; x++) {
      if (!input_map[y][x] && !visited[y][x]) {
        result++;
        result_vector.push_back(dfs(y, x));
      }
    }
  }

  sort(result_vector.begin(), result_vector.end());

  cout << result << endl;
  for (int area : result_vector) {
    cout << area << " ";
  }
}
