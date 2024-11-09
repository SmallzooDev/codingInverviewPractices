#include "../../common/common_headers.h"
using namespace std;

vector<int> dwarfs;
int height;

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> height;
    dwarfs.push_back(height);
  }

  sort(dwarfs.begin(), dwarfs.end());
  auto start = dwarfs.begin();

  for (auto &dwarf : dwarfs) {
    cout << dwarf;
  }

  return 0;
}
