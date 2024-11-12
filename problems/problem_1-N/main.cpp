#include "../../common/common_headers.h"
// #include <bits/stdc++.h>
using namespace std;

/**
 * Fail ㅠㅠ, README.md 참고
 */
long long modular_exponentiation(long long a, long long b, long long c) {
    long long result = 1;
    a = a % c;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % c;
        }
        a = (a * a) % c;
        b /= 2;
    }

    return result;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << modular_exponentiation(a, b, c) << endl;
    return 0;
}
