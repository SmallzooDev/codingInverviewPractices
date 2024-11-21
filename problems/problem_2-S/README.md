# dfs vs bfs
---
안풀린 dfs 코드
```cpp
#include "../../common/common_headers.h"
// #include <bits/stdc++.h>

 vector<vector<int>> graph_nodes;
 vector<int> visited;
 int node_count, line_count;

 int dfs(int node_number) {
 if (visited[node_number] != 0)
 return visited[node_number];

 int counter = 1;
 for (auto i : graph_nodes[node_number]) {
 counter += dfs(i);
 }

 visited[node_number] = counter;
 return counter;
 }

 int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);

 cin >> node_count >> line_count;

 graph_nodes.resize(node_count + 1);
 visited.assign(node_count + 1, 0);

 for (int i = 0; i < line_count; i++) {
 int trusting, trusted;
 cin >> trusting >> trusted;
 graph_nodes[trusted].push_back(trusting);
 }

 vector<int> result(node_count + 1, 0);
 int max_count = 0;

 for (int i = 1; i <= node_count; i++) {
 if (visited[i] == 0) {
 result[i] = dfs(i);
 }
 max_count = max(max_count, result[i]);
 }

 for (int i = 1; i <= node_count; i++) {
 if (result[i] == max_count) {
 cout << i << " ";
 }
 }

 cout << endl;
 return 0;
 }

```
