#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

map<int, int> count_map;
map<int, int> first_appearance;
int length, limit;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) {
    return first_appearance[a.first] < first_appearance[b.first];
  }
  return a.second > b.second;
}

int main() {
  cin >> length >> limit;

  for (int i = 0; i < length; i++) {
    int temp;
    cin >> temp;

    count_map[temp] += 1;

    if (first_appearance.find(temp) == first_appearance.end()) {
      first_appearance[temp] = i;
    }
  }

  vector<pair<int, int>> sort_vector(count_map.begin(), count_map.end());
  sort(sort_vector.begin(), sort_vector.end(), compare);

  for (const auto &p : sort_vector) {
    for (int i = 0; i < p.second; i++) {
      cout << p.first << " ";
    }
  }

  return 0;
}
