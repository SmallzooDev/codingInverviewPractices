#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

int n, m, input_count, result;
int basket_start, basket_end;

bool can_hold(int apple) {
  return basket_start <= apple && apple <= basket_end;
}

void move_to_hold(int apple) {
  if (apple > basket_end) {
    result += apple - basket_end;
    basket_start += apple - basket_end;
    basket_end = apple;
  } else if (apple < basket_start) {
    result += basket_start - apple;
    basket_end -= basket_start - apple;
    basket_start = apple;
  }
}

int main() {
  cin >> n >> m >> input_count;
  basket_start = 1;
  basket_end = m;

  for (int i = 0; i < input_count; i++) {
    int apple;
    cin >> apple;
    if (!can_hold(apple)) {
      move_to_hold(apple);
    }
  }

  cout << result << endl;
}
