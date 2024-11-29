#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

struct Point {
  int y, x;
};

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int max_y, max_x;
vector<vector<char>> input_map;
vector<vector<int>> visited;
vector<Point> fire_points;

vector<Point> fire_cross(Point point) {
  vector<Point> result;
  for (int i = 0; i < 4; i++) {
    int next_y = point.y + dy[i];
    int next_x = point.x + dx[i];

    if (next_y < 0 || next_x < 0 || next_y >= max_y || next_x >= max_x)
      continue;

    if (input_map[next_y][next_x] != '.')
      continue;

    input_map[next_y][next_x] = 'F';
    result.push_back({next_y, next_x});
  }
  return result;
}

void progress_fire() {
  vector<Point> tmp;
  for (auto f : fire_points) {
    vector<Point> new_fire = fire_cross(f);
    tmp.insert(tmp.end(), new_fire.begin(), new_fire.end());
  }
  fire_points = tmp;
}

int bfs(Point start) {
  queue<Point> q;
  visited[start.y][start.x] = 1;
  q.push(start);
  int counter = 0;

  while (!q.empty()) {
    int q_size = q.size();
    counter++;
    progress_fire();

    for (int i = 0; i < q_size; i++) {
      Point front = q.front();
      q.pop();

      for (int d = 0; d < 4; d++) {
        int next_y = front.y + dy[d];
        int next_x = front.x + dx[d];

        if (next_y < 0 || next_x < 0 || next_y >= max_y || next_x >= max_x) {
          return counter;
        }

        if (visited[next_y][next_x] || input_map[next_y][next_x] == '#' ||
            input_map[next_y][next_x] == 'F')
          continue;

        visited[next_y][next_x] = 1;
        q.push({next_y, next_x});
      }
    }
  }

  return -1;
}

int main() {
  cin >> max_y >> max_x;
  input_map = vector<vector<char>>(max_y, vector<char>(max_x));
  visited = vector<vector<int>>(max_y, vector<int>(max_x, 0));
  Point jihoon;

  for (int i = 0; i < max_y; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < max_x; j++) {
      input_map[i][j] = tmp[j];
      if (tmp[j] == 'J') {
        jihoon = {i, j};
        input_map[i][j] = '.';
      }
      if (tmp[j] == 'F') {
        fire_points.push_back({i, j});
      }
    }
  }

  int result = bfs(jihoon);
  if (result == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << result << endl;
  }

  return 0;
}
