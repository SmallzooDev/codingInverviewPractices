#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input_map;
int length;

int is_mono(int x, int y, int size) {
  int first_value = input_map[x][y];
  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++) {
      if (input_map[i][j] != first_value)
        return -1;
    }
  }
  return first_value;
}

string quad_tree(int x, int y, int size) {
  int check = is_mono(x, y, size);
  if (check != -1) {
    return to_string(check);
  }

  int half = size / 2;
  return "(" +
         quad_tree(x, y, half) +
         quad_tree(x, y + half, half) +
         quad_tree(x + half, y, half) +
         quad_tree(x + half, y + half, half) +
         ")";
}

int main() {
  cin >> length;
  input_map = vector<vector<int>>(length, vector<int>(length));

  for (int i = 0; i < length; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < length; j++) {
      input_map[i][j] = row[j] - '0';
    }
  }

  cout << quad_tree(0, 0, length) << endl;
  return 0;
}
