#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;
const string NONE_OUT = "PREDAJA";

int main() {
  map<char, int> entry_map;
  int count = 0;
  string result = "";
  cin >> count;
  for (int i = 0; i < count; i++) {
    string tmp;
    cin >> tmp;
    if (entry_map.find(*tmp.begin()) != entry_map.end()) {
      entry_map[*tmp.begin()] += 1;
    } else {
      entry_map[*tmp.begin()] = 1;
    }
  }

  for (const auto &pair : entry_map) {
    if (pair.second >= 5)
      result += pair.first;
  }

  if (result.empty()) {
    cout << NONE_OUT << endl;
  } else {
    sort(result.begin(), result.end());
    cout << result << endl;
  }
}
