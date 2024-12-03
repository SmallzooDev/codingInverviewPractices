#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int N;
vector<char> expression;
int result = INT_MIN;

int calculate_two(int num1, int num2, char op) {
  if (op == '+')
    return num1 + num2;
  else if (op == '-')
    return num1 - num2;
  else if (op == '*')
    return num1 * num2;
  throw invalid_argument("Invalid operator");
}

void dfs(int idx, int current_result) {
  if (idx >= N) {
    result = max(result, current_result);
    return;
  }

  char op = expression[idx];
  int next_num = expression[idx + 1] - '0';

  int no_bracket_result = calculate_two(current_result, next_num, op);
  dfs(idx + 2, no_bracket_result);

  if (idx + 2 < N) {
    int bracket_result =
        calculate_two(next_num, expression[idx + 3] - '0', expression[idx + 2]);
    int with_bracket_result = calculate_two(current_result, bracket_result, op);
    dfs(idx + 4, with_bracket_result);
  }
}

int main() {
  cin >> N;
  string tmp;
  cin >> tmp;

  for (char c : tmp) {
    expression.push_back(c);
  }

  int initial_num = expression[0] - '0';
  dfs(1, initial_num);

  cout << result << endl;
  return 0;
}
