#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

char intoRot13(char ch) {
  if ('a' <= ch && ch <= 'z') {
    ch = (ch - 'a' + 13) % 26 + 'a';
  } else if ('A' <= ch && ch <= 'Z') {
    ch = (ch - 'A' + 13) % 26 + 'A';
  }
  return ch;
}

int main() {
  string input;
  getline(cin, input);
  for (char &ch : input) {
    ch = intoRot13(ch);
  }

  cout << input;
  return 0;
}
