#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int N, K;
int visited[MAX];
int ways[MAX];

void bfs() {
  queue<int> q;
  q.push(N);
  visited[N] = 0;
  ways[N] = 1;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int next : {curr - 1, curr + 1, curr * 2}) {
      if (next < 0 || next >= MAX)
        continue;

      if (visited[next] == -1) {
        visited[next] = visited[curr] + 1;
        ways[next] = ways[curr];
        q.push(next);
      } else if (visited[next] == visited[curr] + 1) {
        ways[next] += ways[curr];
      }
    }
  }
}

int main() {
  cin >> N >> K;
  memset(visited, -1, sizeof(visited));

  bfs();

  cout << visited[K] << endl;
  cout << ways[K] << endl;

  return 0;
}
