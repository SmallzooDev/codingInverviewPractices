#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

string remove_leading_zeros(const string &str) {
  size_t start = 0;
  while (start < str.size() && str[start] == '0') {
    start++;
  }
  return start == str.size() ? "0" : str.substr(start);
}

bool compare_strings(const string &a, const string &b) {
  if (a.size() == b.size()) {
    return a < b;
  }
  return a.size() < b.size();
}

int main() {
  int input_count;
  string buffer = "";
  vector<string> result;

  cin >> input_count;
  for (int i = 0; i < input_count; i++) {
    string tmp;
    cin >> tmp;

    for (char c : tmp) {
      if (isdigit(c)) {
        buffer.push_back(c);
      } else {
        if (!buffer.empty()) {
          result.push_back(remove_leading_zeros(buffer));
          buffer = "";
        }
      }
    }

    if (!buffer.empty()) {
      result.push_back(remove_leading_zeros(buffer));
      buffer = "";
    }
  }

  sort(result.begin(), result.end(), compare_strings);

  for (const string &num : result) {
    cout << num << endl;
  }

  return 0;
}
