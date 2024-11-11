#include "../../common/common_headers.h"
// #include <bits/stdc++.h>

using namespace std;

const string YES = "DA";
const string NO = "NE";

bool is_match(const string &pattern, const string &name) {
  size_t star_pos = pattern.find('*');
  string prefix = pattern.substr(0, star_pos);
  string suffix = pattern.substr(star_pos + 1);

  if (name.size() < prefix.size() + suffix.size()) {
    return false;
  }

  if (name.substr(0, prefix.size()) != prefix) {
    return false;
  }

  if (name.substr(name.size() - suffix.size()) != suffix) {
    return false;
  }

  return true;
}

int main() {
  int count;
  cin >> count;

  string pattern;
  cin >> pattern;

  vector<string> names(count);
  for (int i = 0; i < count; i++) {
    cin >> names[i];
  }

  for (const string &name : names) {
    if (is_match(pattern, name)) {
      cout << YES << endl;
    } else {
      cout << NO << endl;
    }
  }

  return 0;
}
