#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int counter;
  cin >> counter;

  vector<int> numbers(counter);
  vector<int> result(counter, -1);
  stack<int> s;

  for (int i = 0; i < counter; i++) {
    cin >> numbers[i];
  }

  for (int i = counter - 1; i >= 0; i--) {
    while (!s.empty() && s.top() <= numbers[i]) {
      s.pop();
    }

    if (!s.empty()) {
      result[i] = s.top();
    }

    s.push(numbers[i]);
  }

  for (int i = 0; i < counter; i++) {
    cout << result[i] << ' ';
  }
  cout << '\n';

  return 0;
}
