#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> chicken_point;
vector<pair<int, int>> house_pont;
int final_result = 999999999;

int n, m;

int get_proximate_chicken_point(pair<int, int> &house,
                                vector<pair<int, int>> &current_chicken_point) {
  int result = 999999;
  for (auto i : current_chicken_point) {
    result =
        min(abs(i.first - house.first) + abs(i.second - house.second), result);
  }
  return result;
}

int get_chicken_length(vector<pair<int, int>> &current_chicken_point) {
  int result = 0;
  for (auto i : house_pont) {
    result += get_proximate_chicken_point(i, current_chicken_point);
  }
  return result;
}

void simulate(vector<int> &combination, int from, int to, int start) {
  if (combination.size() == to) {
    vector<pair<int, int>> tmp;
    for (int idx : combination) {
      tmp.push_back(chicken_point[idx]);
    }
    final_result = min(get_chicken_length(tmp), final_result);
    return;
  }

  for (int i = start; i < from; i++) {
    combination.push_back(i);
    simulate(combination, from, to, i + 1);
    combination.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      int tmp;
      cin >> tmp;
      if (tmp == 1) {
        house_pont.push_back({y, x});
      } else if (tmp == 2) {
        chicken_point.push_back({y, x});
      }
    }
  }
  vector<int> combination;
  simulate(combination, chicken_point.size(), m, 0);
  cout << final_result;
}
