#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int max_level;
vector<vector<int>> tree;
vector<int> input_nodes;

vector<int> split(const string &str) {
  vector<int> tokens;
  stringstream ss(str);
  string token;

  while (getline(ss, token, ' ')) {
    tokens.push_back(stoi(token));
  }

  return tokens;
}

void build_tree(int current_level, int start, int end) {
  if (start > end || current_level == max_level) {
    return;
  }

  int mid = (start + end) / 2;

  if (tree.size() <= current_level) {
    tree.push_back({});
  }
  tree[current_level].push_back(input_nodes[mid]);

  build_tree(current_level + 1, start, mid - 1);
  build_tree(current_level + 1, mid + 1, end);
}

int main() {
  cin >> max_level;
  string tmp;
  cin.ignore();
  getline(cin, tmp);

  input_nodes = split(tmp);

  int n = input_nodes.size();
  tree.clear();

  build_tree(0, 0, n - 1);

  for (int i = 0; i < tree.size(); i++) {
    for (int building : tree[i]) {
      cout << building << " ";
    }
    cout << endl;
  }

  return 0;
}
