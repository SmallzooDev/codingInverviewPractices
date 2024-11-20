#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int count_zeros(int number) {
  int counter = 0;
  for (int i = 5; number / i > 0; i *= 5) {
    counter += number / i;
  }
  return counter;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int input_count;
  cin >> input_count;

  for (int i = 0; i < input_count; i++) {
    int temp;
    cin >> temp;
    cout << count_zeros(temp) << "\n";
  }

  return 0;
}
