#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

const string ERROR_RESPONSE = "I'm Sorry Hansoo";

int main() {
  map<char, int> word_count_map;
  string input;
  string first_half = "", second_half = "", middle_char = "";

  cin >> input;

  for (char ch : input) {
    word_count_map[ch]++;
  }

  int odd_count = 0;
  for (auto &entry : word_count_map) {
    if (entry.second % 2 == 1) {
      odd_count++;
      middle_char = string(1, entry.first);
    }
  }

  if (odd_count > 1) {
    cout << ERROR_RESPONSE << '\n';
    return 0;
  }

  for (auto &entry : word_count_map) {
    first_half += string(entry.second / 2, entry.first);
  }

  sort(first_half.begin(), first_half.end());

  second_half = first_half;
  reverse(second_half.begin(), second_half.end());

  string palindrome = first_half + middle_char + second_half;

  cout << palindrome << '\n';

  return 0;
}
