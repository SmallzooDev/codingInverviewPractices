#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int main() {
  bool is_palindrome = true;
  string input;
  cin >> input;
  auto start = input.begin();
  auto end = input.end() - 1;

  while (start < end) {
    if (*start != *end) {
      is_palindrome = false;
      break;
    };

    start++;
    end--;
  }

  cout << (is_palindrome ? 1 : 0) << endl;
}
