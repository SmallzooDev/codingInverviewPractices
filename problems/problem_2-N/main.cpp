#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

const char open = '(';
const char close = ')';

bool is_vps(string input) {
  stack<char> input_stack;
  for (char a : input) {
    if (a == open)
      input_stack.push(a);
    if (a == close) {
      if (input_stack.empty())
        return false;
      if (input_stack.top() != open)
        return false;
      input_stack.pop();
    }
  }

  return input_stack.empty();
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if (is_vps(temp))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
