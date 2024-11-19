#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int n;
int max_height = 1;
int max_count = 0;
vector<vector<int>> input_map;
vector<vector<int>> visited_map;
vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

void dfs(int y, int x, int height) {
  if (visited_map[y][x] || input_map[y][x] <= height)
    return;
  visited_map[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int next_y = y + dy[i];
    int next_x = x + dx[i];
    if (next_y < 0 || next_x < 0 || next_x >= n || next_y >= n)
      continue;
    dfs(next_y, next_x, height);
  }
}

int calc_area_count(int height) {
  visited_map = vector<vector<int>>(n, vector<int>(n, 0));
  int result = 0;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (input_map[y][x] > height && !visited_map[y][x]) {
        ++result;
        dfs(y, x, height);
      }
    }
  }
  return result;
}

int main() {
  cin >> n;
  input_map = vector<vector<int>>(n, vector<int>(n, 0));

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cin >> input_map[y][x];
      if (input_map[y][x] > max_height)
        max_height = input_map[y][x];
    }
  }

  for (int i = 0; i <= max_height; i++) {
    int counter = calc_area_count(i);
    if (counter > max_count)
      max_count = counter;
  }

  cout << max_count;
}
