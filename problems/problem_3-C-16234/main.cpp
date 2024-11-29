#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int max_length;
int low_bound, high_bound;

vector<vector<int>> country_map;
vector<vector<bool>> visited;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool is_mergeable(int a, int b) {
  int diff = abs(a - b);
  return low_bound <= diff && diff <= high_bound;
}

bool bfs(int start_y, int start_x, vector<pair<int, int>> &union_countries,
         int &total_population) {
  queue<pair<int, int>> q;
  q.push({start_y, start_x});
  visited[start_y][start_x] = true;
  union_countries.push_back({start_y, start_x});
  total_population = country_map[start_y][start_x];

  while (!q.empty()) {
    auto [cur_y, cur_x] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      if (ny >= 0 && ny < max_length && nx >= 0 && nx < max_length &&
          !visited[ny][nx]) {
        if (is_mergeable(country_map[cur_y][cur_x], country_map[ny][nx])) {
          visited[ny][nx] = true;
          q.push({ny, nx});
          union_countries.push_back({ny, nx});
          total_population += country_map[ny][nx];
        }
      }
    }
  }

  return union_countries.size() > 1;
}

int main() {
  cin >> max_length >> low_bound >> high_bound;
  country_map = vector(max_length, vector(max_length, 0));
  for (int i = 0; i < max_length; i++) {
    for (int j = 0; j < max_length; j++) {
      cin >> country_map[i][j];
    }
  }

  int days = 0;
  while (true) {
    visited = vector(max_length, vector<bool>(max_length, false));
    bool moved = false;

    for (int i = 0; i < max_length; i++) {
      for (int j = 0; j < max_length; j++) {
        if (!visited[i][j]) {
          vector<pair<int, int>> union_countries;
          int total_population = 0;
          if (bfs(i, j, union_countries, total_population)) {
            moved = true;
            int new_population = total_population / union_countries.size();
            for (auto [y, x] : union_countries) {
              country_map[y][x] = new_population;
            }
          }
        }
      }
    }

    if (!moved)
      break;
    days++;
  }

  cout << days << endl;
  return 0;
}
