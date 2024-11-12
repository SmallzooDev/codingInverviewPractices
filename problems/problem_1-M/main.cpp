#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

bool is_good_word(const string &word) {
  stack<char> st;

  for (char c : word) {
    if (!st.empty() && st.top() == c) {
      st.pop();
    } else {
      st.push(c);
    }
  }

  return st.empty();
}

int main() {
  int N;
  cin >> N;
  int result = 0;

  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;

    if (is_good_word(word)) {
      result++;
    }
  }

  cout << result << endl;

  return 0;
}
