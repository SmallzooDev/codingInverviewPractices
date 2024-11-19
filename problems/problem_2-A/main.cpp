#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

void bfs(vector<vector<int>> &visited_map, const vector<vector<int>> &map) {
  queue<pair<int, int>> visit_queue;
  visited_map[0][0] = 1;
  visit_queue.push({0, 0});

  while (!visit_queue.empty()) {
    pair<int, int> front = visit_queue.front();
    visit_queue.pop();

    for (int i = 0; i < 4; i++) {
      int next_y = front.first + dy[i];
      int next_x = front.second + dx[i];

      if (next_x < 0 || next_y < 0 || next_y >= n || next_x >= m)
        continue;

      if (visited_map[next_y][next_x] || map[next_y][next_x] == 0)
        continue;

      visited_map[next_y][next_x] = visited_map[front.first][front.second] + 1;
      visit_queue.push({next_y, next_x});
    }
  }
}

int main() {
  cin >> n >> m;
  vector<vector<int>> map(n, vector<int>(m));
  vector<vector<int>> visited_map(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < m; j++) {
      map[i][j] = row[j] - '0';
    }
  }

  bfs(visited_map, map);
  cout << visited_map[n - 1][m - 1] << endl;
  return 0;
}
