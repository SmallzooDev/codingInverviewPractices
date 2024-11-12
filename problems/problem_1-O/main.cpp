#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int find_minimum_length(int n) {
  int remainder = 1;
  int length = 1;

  while (remainder % n != 0) {
    remainder = (remainder * 10 + 1) % n;
    length++;
  }
  return length;
}

int main() {
  int n;
  while (cin >> n) {
    cout << find_minimum_length(n) << endl;
  }
  return 0;
}
