#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

struct State {
  int scv[3];
  int steps;
};

int bfs(vector<int> initial) {
  queue<State> q;
  set<vector<int>> visited;

  sort(initial.rbegin(), initial.rend());
  q.push({{initial[0], initial[1], initial[2]}, 0});
  visited.insert(initial);

  while (!q.empty()) {
    State current = q.front();
    q.pop();

    int a = current.scv[0];
    int b = current.scv[1];
    int c = current.scv[2];
    int steps = current.steps;

    if (a <= 0 && b <= 0 && c <= 0) {
      return steps;
    }

    vector<int> damage = {9, 3, 1};
    do {
      int na = max(0, a - damage[0]);
      int nb = max(0, b - damage[1]);
      int nc = max(0, c - damage[2]);

      vector<int> next_scv = {na, nb, nc};
      sort(next_scv.rbegin(), next_scv.rend());

      if (visited.find(next_scv) == visited.end()) {
        visited.insert(next_scv);
        q.push({{next_scv[0], next_scv[1], next_scv[2]}, steps + 1});
      }
    } while (next_permutation(damage.begin(), damage.end()));
  }

  return -1;
}

int main() {
  int cnt;
  cin >> cnt;

  vector<int> scvs(3, 0);
  for (int i = 0; i < cnt; i++) {
    cin >> scvs[i];
  }

  cout << bfs(scvs) << endl;
  return 0;
}
