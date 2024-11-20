#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input_map;
vector<vector<int>> visited_map;

vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};

vector<pair<int, int>> safety_area_list;
vector<pair<int, int>> virus_area_list;
int n, m;

void release_virus(int y, int x) {
  visited_map[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int next_y = y + dy[i];
    int next_x = x + dx[i];
    if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
      continue;
    if (visited_map[next_y][next_x] || input_map[next_y][next_x] != 0)
      continue;
    release_virus(next_y, next_x);
  }
}

int simulate() {
  visited_map = vector<vector<int>>(n, vector<int>(m, 0));

  for (auto virus : virus_area_list) {
    if (!visited_map[virus.first][virus.second]) {
      release_virus(virus.first, virus.second);
    }
  }

  int safe_area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (input_map[i][j] == 0 && !visited_map[i][j]) {
        safe_area++;
      }
    }
  }
  return safe_area;
}

int main() {
  cin >> n >> m;
  input_map = vector<vector<int>>(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int temp;
      cin >> temp;
      input_map[i][j] = temp;
      if (temp == 0) {
        safety_area_list.push_back({i, j});
      } else if (temp == 2) {
        virus_area_list.push_back({i, j});
      }
    }
  }

  int max_safe_area = 0;
  for (int i = 0; i < safety_area_list.size(); i++) {
    for (int j = i + 1; j < safety_area_list.size(); j++) {
      for (int k = j + 1; k < safety_area_list.size(); k++) {
        input_map[safety_area_list[i].first][safety_area_list[i].second] = 1;
        input_map[safety_area_list[j].first][safety_area_list[j].second] = 1;
        input_map[safety_area_list[k].first][safety_area_list[k].second] = 1;

        int safe_area = simulate();
        max_safe_area = max(max_safe_area, safe_area);

        input_map[safety_area_list[i].first][safety_area_list[i].second] = 0;
        input_map[safety_area_list[j].first][safety_area_list[j].second] = 0;
        input_map[safety_area_list[k].first][safety_area_list[k].second] = 0;
      }
    }
  }

  cout << max_safe_area << endl;
  return 0;
}
