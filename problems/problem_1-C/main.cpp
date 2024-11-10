// #include <bits/stdc++.h>
#include "../../common/common_headers.h"
using namespace std;

int main() {
  int time_table[100] = {0};
  map<int, int> price_table;
  int result = 0;

  for (int i = 1; i < 4; i++) {
    int tmp;
    cin >> tmp;
    price_table[i] = tmp;
  }

  for (int i = 0; i < 3; i++) {
    int start, end;
    cin >> start;
    cin >> end;
    for (int j = start - 1; j < end - 1; j++) {
      time_table[j] += 1;
    }
  }

  for (int i = 0; i < 100; i++) {
    if (time_table[i] > 0) {
      result += price_table[time_table[i]] * time_table[i];
    }
  }

  cout << result;
}
