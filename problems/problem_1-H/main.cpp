#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int main() {
  int size;
  int interval;
  int result = INT_MIN;
  vector<int> temperatures;

  cin >> size;
  cin >> interval;

  for (int i = 0; i < size; i++) {
    int temp;
    cin >> temp;
    temperatures.push_back(temp);
  }

  auto first = temperatures.begin();
  auto last = first + interval;

  while (last <= temperatures.end()) {
    int sum = 0;
    for (auto it = first; it != last; ++it) {
      sum += *it;
    }

    if (sum > result) {
      result = sum;
    }

    ++first;
    ++last;
  }

  cout << result << endl;
  return 0;
}
