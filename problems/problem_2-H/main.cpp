#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

char vowels[] = {'a', 'e', 'i', 'o', 'u'};

bool is_vowel(char c) {
  for (char v : vowels) {
    if (c == v) {
      return true;
    }
  }
  return false;
}

bool validate_password(string password) {
  int vowel_counter = 0;
  int consonant_counter = 0;
  char last_char = '\0';
  bool contains_vowel = false;

  for (size_t i = 0; i < password.size(); ++i) {
    char c = password[i];

    if (is_vowel(c)) {
      contains_vowel = true;
      vowel_counter++;
      consonant_counter = 0;
    } else {
      consonant_counter++;
      vowel_counter = 0;
    }

    if (vowel_counter > 2 || consonant_counter > 2) {
      return false;
    }

    if (i > 0 && c == last_char && c != 'e' && c != 'o') {
      return false;
    }

    last_char = c;
  }

  if (!contains_vowel) {
    return false;
  }

  return true;
}

int main() {
  bool is_end = false;

  while (!is_end) {
    string temp;
    cin >> temp;
    if (temp == "end") {
      is_end = true;
      continue;
    }

    if (validate_password(temp)) {
      cout << "<" << temp << "> is acceptable." << endl;
    } else {
      cout << "<" << temp << "> is not acceptable." << endl;
    }
  }

  return 0;
}
