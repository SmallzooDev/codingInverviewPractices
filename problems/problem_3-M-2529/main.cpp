#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int visited[10] = {0};
vector<string> results;

size_t length;

bool is_correct_expression(char a, char b, char oper) {
  if (oper == '>') {
    return a > b;
  } else {
    return a < b;
  }
}

void dfs(string current, const vector<char> &opers) {
  if (current.size() >= length + 1) {
    results.push_back(current);
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (visited[i])
      continue;

    if (current.empty()) {
      current.push_back(numbers[i] + '0');
      visited[i] = 1;
      dfs(current, opers);
      current.pop_back();
      visited[i] = 0;
    } else {
      if (current.size() - 1 >= opers.size() ||
          !is_correct_expression(current.back(), numbers[i] + '0',
                                 opers[current.size() - 1]))
        continue;

      current.push_back(numbers[i] + '0');
      visited[i] = 1;
      dfs(current, opers);
      current.pop_back();
      visited[i] = 0;
    }
  }
}

int main() {
  cin >> length;
  vector<char> opers(length);
  for (size_t i = 0; i < length; i++) {
    cin >> opers[i];
  }

  dfs("", opers);
  cout << *(results.end() - 1) << endl;
  cout << *results.begin() << endl;
}
