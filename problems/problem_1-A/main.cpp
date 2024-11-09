#include "../../common/common_headers.h"
#include <numeric>
// #include <bits/stdc++.h>
using namespace std;

pair<int, int> findFakeDwarfs(vector<int> &dwarfs) {
  int sum = accumulate(dwarfs.begin(), dwarfs.end(), 0);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < i; j++) {
      if (sum - dwarfs[i] - dwarfs[j] == 100)
        return pair(i, j);
    }
  }

  return pair(-1, -1);
}
int main() {
  vector<int> dwarfs;
  int height;
  vector<int> result;

  for (int i = 0; i < 9; i++) {
    cin >> height;
    dwarfs.push_back(height);
  }

  pair<int, int> fake_dewarfs = findFakeDwarfs(dwarfs);

  for (int i = 0; i < 9; i++) {
    if (i != fake_dewarfs.first && i != fake_dewarfs.second)
      result.push_back(dwarfs[i]);
  }

  sort(result.begin(), result.end());

  for (auto i : result)
    cout << i << ' ';
  return 0;
}
