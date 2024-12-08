#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int n, m, h;
vector<vector<int>> ladders;

int move(int start) {
  int current = start;
  for (int i = 0; i < h; i++) {
    if (ladders[current][i] != -1) {
      current = ladders[current][i];
    }
  }
  return current;
}

bool is_all_matched_ladder() {
  for (int i = 0; i < n; i++) {
    if (i != move(i))
      return false;
  }
  return true;
}

bool dfs(int depth, int max_depth, int start_x, int start_y) {
  if (depth > max_depth)
    return false;
  if (is_all_matched_ladder())
    return true;

  for (int x = start_x; x < n - 1; x++) {
    for (int y = (x == start_x ? start_y : 0); y < h; y++) {
      if (ladders[x][y] == -1 && ladders[x + 1][y] == -1) {
        ladders[x][y] = x + 1;
        ladders[x + 1][y] = x;

        if (dfs(depth + 1, max_depth, x, y))
          return true;

        ladders[x][y] = -1;
        ladders[x + 1][y] = -1;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> h;
  ladders = vector<vector<int>>(n, vector<int>(h, -1));

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ladders[b - 1][a - 1] = b;
    ladders[b][a - 1] = b - 1;
  }

  int answer = -1;
  for (int max_depth = 0; max_depth <= 3; max_depth++) {
    if (dfs(0, max_depth, 0, 0)) {
      answer = max_depth;
      break;
    }
  }

  cout << answer << endl;
  return 0;
}
