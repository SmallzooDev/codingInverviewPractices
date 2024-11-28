#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

struct Point {
  int y, x;
};

vector<vector<int>> treasure;
vector<Point> land_points;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int max_y, max_x;

int bfs(Point start) {
  int result = 0;
  vector<vector<int>> visited(max_y, vector<int>(max_x, -1));
  queue<Point> q;

  visited[start.y][start.x] = 0;
  q.push(start);

  while (!q.empty()) {
    Point current = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int next_y = current.y + dy[i];
      int next_x = current.x + dx[i];

      if (next_y < 0 || next_x < 0 || next_y >= max_y || next_x >= max_x)
        continue;
      if (!treasure[next_y][next_x])
        continue;
      if (visited[next_y][next_x] != -1)
        continue;

      visited[next_y][next_x] = visited[current.y][current.x] + 1;
      result = max(result, visited[next_y][next_x]);
      q.push({next_y, next_x});
    }
  }

  return result;
}

int main() {
  cin >> max_y >> max_x;
  treasure = vector(max_y, vector(max_x, 0));

  for (int i = 0; i < max_y; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < tmp.size(); j++) {
      if (tmp[j] == 'L') {
        treasure[i][j] = 1;
        land_points.push_back({i, j});
      }
    }
  }

  int result = INT_MIN;
  for (Point i : land_points) {
    result = max(result, bfs(i));
  }

  cout << result << endl;
  return 0;
}
