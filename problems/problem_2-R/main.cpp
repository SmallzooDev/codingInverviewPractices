#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

void delete_subtree(int node, vector<vector<int>> &tree,
                    vector<bool> &deleted) {
  deleted[node] = true;
  for (int child : tree[node]) {
    delete_subtree(child, tree, deleted);
  }
}

int count_leaves(int node, vector<vector<int>> &tree, vector<bool> &deleted) {
  if (deleted[node])
    return 0;
  if (tree[node].empty())
    return 1;

  int leaf_count = 0;
  for (int child : tree[node]) {
    if (!deleted[child]) {
      leaf_count += count_leaves(child, tree, deleted);
    }
  }

  if (leaf_count == 0)
    return 1;
  return leaf_count;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> tree(n);
  vector<bool> deleted(n, false);
  int root = -1;

  for (int i = 0; i < n; i++) {
    int parent;
    cin >> parent;
    if (parent == -1) {
      root = i;
    } else {
      tree[parent].push_back(i);
    }
  }

  int delete_node;
  cin >> delete_node;

  if (delete_node == root) {
    cout << 0 << endl;
    return 0;
  }

  delete_subtree(delete_node, tree, deleted);

  int leaf_count = count_leaves(root, tree, deleted);
  cout << leaf_count << endl;

  return 0;
}
