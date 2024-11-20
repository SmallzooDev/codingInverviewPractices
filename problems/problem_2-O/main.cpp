#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

bool is_balanced(string input) {
  stack<char> input_stack;
  for (char a : input) {
    if (a == '(' || a == '[') {
      input_stack.push(a);
    } else if (a == ')' || a == ']') {
      if (input_stack.empty())
        return false;
      if ((a == ')' && input_stack.top() != '(') ||
          (a == ']' && input_stack.top() != '[')) {
        return false;
      }
      input_stack.pop();
    }
  }
  return input_stack.empty();
}

int main() {
  string input;
  while (true) {
    getline(cin, input);
    if (input == ".")
      break;
    if (is_balanced(input)) {
      cout << "yes" << '\n';
    } else {
      cout << "no" << '\n';
    }
  }
  return 0;
}
