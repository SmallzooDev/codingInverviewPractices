#include "../../common/common_headers.h"
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

vector<int> make_forecast(string input_string) {
  vector<int> result;
  int counter = 0;
  bool is_found_c = false;

  for (char c : input_string) {
    if (!is_found_c && c != 'c') {
      result.push_back(-1);
      continue;
    }

    if (c == 'c') {
      is_found_c = true;
      counter = 0;
      result.push_back(counter);
      continue;
    }

    ++counter;
    result.push_back(counter);
  }

  return result;
}

int main() {
  int y, x;
  cin >> y >> x;

  for (int i = 0; i < y; i++) {
    string temp;
    cin >> temp;
    result.push_back(make_forecast(temp));
  }

  for (auto i : result) {
    for (int j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}
