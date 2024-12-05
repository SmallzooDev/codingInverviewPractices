#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

struct Point {
  int y, x;
};

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> visited;
vector<vector<char>> class_map;
int N, M;
int zoo_y, zoo_x, friend_y, friend_x;

int bfs(Point start) {
  deque<Point> dq;
  dq.push_front(start);
  visited[start.y][start.x] = 0;

  while (!dq.empty()) {
    Point curr = dq.front();
    dq.pop_front();

    if (curr.y == friend_y && curr.x == friend_x) {
      return visited[curr.y][curr.x];
    }

    for (int i = 0; i < 4; i++) {
      int next_y = curr.y + dy[i];
      int next_x = curr.x + dx[i];

      if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M)
        continue;
      if (visited[next_y][next_x] != -1)
        continue;

      if (class_map[next_y][next_x] == '1') {
        dq.push_back({next_y, next_x});
        visited[next_y][next_x] = visited[curr.y][curr.x] + 1;
      } else {
        dq.push_front({next_y, next_x});
        visited[next_y][next_x] = visited[curr.y][curr.x];
      }
    }
  }
  return -1;
}

int main() {
  cin >> N >> M;
  cin >> zoo_y >> zoo_x >> friend_y >> friend_x;
  zoo_y--;
  zoo_x--;
  friend_y--;
  friend_x--;

  class_map = vector<vector<char>>(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> class_map[i][j];
    }
  }

  visited = vector<vector<int>>(N, vector<int>(M, -1));

  cout << bfs({zoo_y, zoo_x}) + 1 << endl;
  return 0;
}
