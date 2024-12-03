#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int N, K;
int visited[MAX];
int parent[MAX];

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 0;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    if (current == K)
      return;

    for (int next : {current - 1, current + 1, current * 2}) {
      if (next < 0 || next >= MAX)
        continue;
      if (visited[next] != -1)
        continue;
      visited[next] = visited[current] + 1;
      parent[next] = current;
      q.push(next);
    }
  }
}

vector<int> get_path(int start, int end) {
  vector<int> path;
  while (start != end) {
    path.push_back(end);
    end = parent[end];
  }
  path.push_back(start);

  reverse(path.begin(), path.end());
  return path;
}

int main() {
  cin >> N >> K;
  memset(visited, -1, sizeof(visited));
  memset(parent, -1, sizeof(parent));

  bfs(N);

  vector<int> path = get_path(N, K);

  cout << visited[K] << endl;
  for (int pos : path) {
    cout << pos << " ";
  }
  return 0;
}
