#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph_nodes;
vector<int> visited, result;
int node_count, line_count;

int bfs(int start_node) {
  queue<int> q;
  vector<bool> local_visited(node_count + 1, false);
  int counter = 0;

  q.push(start_node);
  local_visited[start_node] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    counter++;

    for (int trusting : graph_nodes[current]) {
      if (!local_visited[trusting]) {
        local_visited[trusting] = true;
        q.push(trusting);
      }
    }
  }

  return counter;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> node_count >> line_count;

  graph_nodes.resize(node_count + 1);
  result.resize(node_count + 1, 0);

  for (int i = 0; i < line_count; i++) {
    int trusting, trusted;
    cin >> trusting >> trusted;
    graph_nodes[trusted].push_back(trusting);
  }

  int max_count = 0;

  for (int i = 1; i <= node_count; i++) {
    if (result[i] == 0) {
      result[i] = bfs(i);
      max_count = max(max_count, result[i]);
    }
  }

  for (int i = 1; i <= node_count; i++) {
    if (result[i] == max_count) {
      cout << i << " ";
    }
  }

  cout << endl;
  return 0;
}
