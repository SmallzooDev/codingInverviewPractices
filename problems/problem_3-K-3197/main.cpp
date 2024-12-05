#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

struct Point {
  int y, x;
};

int max_y, max_x;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<char>> duck_map;
vector<Point> duck_points;

queue<Point> water_queue;
queue<Point> next_water_queue;
queue<Point> swan_queue;
queue<Point> next_swan_queue;
vector<vector<bool>> water_visited;
vector<vector<bool>> swan_visited;

bool is_out_of_bound(Point point) {
  return (point.y < 0 || point.x < 0 || point.y >= max_y || point.x >= max_x);
}

bool match_duck() {
  while (!swan_queue.empty()) {
    Point curr = swan_queue.front();
    swan_queue.pop();

    for (int i = 0; i < 4; i++) {
      int next_y = curr.y + dy[i];
      int next_x = curr.x + dx[i];

      if (is_out_of_bound({next_y, next_x}) || swan_visited[next_y][next_x])
        continue;

      swan_visited[next_y][next_x] = true;
      if (duck_map[next_y][next_x] == 'L') {
        return true;
      }
      if (duck_map[next_y][next_x] == '.') {
        swan_queue.push({next_y, next_x});
      } else if (duck_map[next_y][next_x] == 'X') {
        next_swan_queue.push({next_y, next_x});
      }
    }
  }
  return false;
}

void melt_ice() {
  while (!water_queue.empty()) {
    Point curr = water_queue.front();
    water_queue.pop();

    for (int i = 0; i < 4; i++) {
      int next_y = curr.y + dy[i];
      int next_x = curr.x + dx[i];

      if (is_out_of_bound({next_y, next_x}) || water_visited[next_y][next_x])
        continue;

      water_visited[next_y][next_x] = true;
      if (duck_map[next_y][next_x] == 'X') {
        duck_map[next_y][next_x] = '.';
        next_water_queue.push({next_y, next_x});
      }
    }
  }

  swap(water_queue, next_water_queue);
}

int main() {
  cin >> max_y >> max_x;
  duck_map = vector<vector<char>>(max_y, vector<char>(max_x));
  water_visited = vector<vector<bool>>(max_y, vector<bool>(max_x, false));
  swan_visited = vector<vector<bool>>(max_y, vector<bool>(max_x, false));

  for (int i = 0; i < max_y; i++) {
    for (int j = 0; j < max_x; j++) {
      cin >> duck_map[i][j];
      if (duck_map[i][j] != 'X') {
        water_queue.push({i, j});
        water_visited[i][j] = true;
      }
      if (duck_map[i][j] == 'L') {
        duck_points.push_back({i, j});
      }
    }
  }

  swan_queue.push(duck_points[0]);
  swan_visited[duck_points[0].y][duck_points[0].x] = true;

  int days = 0;
  while (true) {
    if (match_duck()) {
      cout << days << endl;
      break;
    }
    melt_ice();
    swap(swan_queue, next_swan_queue);
    days++;
  }
  return 0;
}
