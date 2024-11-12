#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int get_cases(map<string, int>& clothes_map) {
  int result = 1;
  for (auto entry : clothes_map) {
    result *= entry.second + 1;
  }
  return result - 1;
}

int main() {
  int case_count = 0;
  cin >> case_count;
  map<string, int> tmp_map;

  for (int i = 0; i < case_count; i++) {
    int entry_count = 0;
    cin >> entry_count;

    for (int j = 0; j < entry_count; j++) {
      string trash, key;
      cin >> trash >> key;
      
      if (tmp_map.find(key) != tmp_map.end()) {
        tmp_map[key] += 1;
      } else {
        tmp_map[key] = 1;
      }
    }

    cout << get_cases(tmp_map) << '\n';
    tmp_map.clear();
  }
}
