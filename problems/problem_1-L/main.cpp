#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int main() {
  int count, magic_number;
  int result = 0;
  unordered_set<int> seen;

  cin >> count >> magic_number;
  vector<int> numbers(count);

  for (int i = 0; i < count; i++) {
    cin >> numbers[i];
  }

  for (int i = 0; i < count; i++) {
    int complement = magic_number - numbers[i];
    if (seen.find(complement) != seen.end()) {
      result++;
    }
    seen.insert(numbers[i]);
  }

  cout << result << endl;
  return 0;
}
