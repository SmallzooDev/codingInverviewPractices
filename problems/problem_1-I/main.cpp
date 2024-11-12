#include "../../common/common_headers.h"
// #include <bits/stdc++.h>

using namespace std;

bool is_number_input(const string &input_string) {
    for (char c : input_string) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int poke_count, question_count;
    vector<string> poke_list;
    unordered_map<string, int> poke_map;

    cin >> poke_count >> question_count;
    
    poke_list.resize(poke_count);
    
    for (int i = 0; i < poke_count; i++) {
        cin >> poke_list[i];
        poke_map[poke_list[i]] = i;
    }

    for (int i = 0; i < question_count; i++) {
        string question;
        cin >> question;

        if (is_number_input(question)) {
            int index = stoi(question) - 1;
            cout << poke_list[index] << '\n';
        } else {
            cout << poke_map[question] + 1 << '\n';
        }
    }

    return 0;
}
