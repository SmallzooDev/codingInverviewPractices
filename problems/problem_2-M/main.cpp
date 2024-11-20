#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  int counter = 0;
  int num = 666;

  while (true) {
    if (to_string(num).find("666") != string::npos) {
      counter++;
      if (counter == n) {
        cout << num << '\n';
        break;
      }
    }
    num++;
  }

  return 0;
}
