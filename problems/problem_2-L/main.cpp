#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

const int TOTAL_TIME = 48 * 60;

vector<string> split(const string &str, char delimiter) {
  vector<string> tokens;
  stringstream ss(str);
  string token;

  while (getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

int get_second(string input_time) {
  vector<string> splited = split(input_time, ':');
  return stoi(splited[0]) * 60 + stoi(splited[1]);
}

string parse_time(int time) {
  string minutes = to_string(time / 60);
  string seconds = to_string(time % 60);
  if (seconds.size() == 1)
    seconds = "0" + seconds;
  if (minutes.size() == 1)
    minutes = "0" + minutes;
  return minutes + ":" + seconds;
}

int main() {
  int counter;
  cin >> counter;

  pair<int, int> score = {0, 0};
  int first_team_time = 0, second_team_time = 0;
  int last_time = 0;

  for (int i = 0; i < counter; i++) {
    int team;
    string tmp;
    cin >> team >> tmp;
    int current_time = get_second(tmp);

    if (score.first > score.second) {
      first_team_time += (current_time - last_time);
    } else if (score.second > score.first) {
      second_team_time += (current_time - last_time);
    }

    if (team == 1) {
      score.first++;
    } else {
      score.second++;
    }

    last_time = current_time;
  }

  if (score.first > score.second) {
    first_team_time += (TOTAL_TIME - last_time);
  } else if (score.second > score.first) {
    second_team_time += (TOTAL_TIME - last_time);
  }

  cout << parse_time(first_team_time) << endl;
  cout << parse_time(second_team_time) << endl;

  return 0;
}
