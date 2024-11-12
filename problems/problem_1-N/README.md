# solution
---

1. 문제를 풀지 못했다.
2. 해설 코드를 봐도 이해를 못해서 추가적으로 모듈러 연산에 대해서 검색했다.
```
(x * y) % c = [(x % c) * (y % c)] % c
(x * x) % c = [(x % c) * (x % c)] % c
```
이게 수학적 근거라고 한다.
즉 x^2 의 나머지값을 이전 차수 x의 나머지 값을 이용해서 구한다는 원리이다.

```cpp
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
```

```cpp
    a = a % c;
```
지수를 나머지값으로 초기화 한다.

```cpp
    if (b % 2 == 1) {
        result = (result * a) % c;
    }
```
지수가 홀수이면 지수를 짝수로 만들기 위해서 양변에 밑을 곱하고 나머지값을 구한다.
a = x 이므로 아래의 논리에 의해 지금 구하고 있는 값의 지수에 +1차가 된다.
`(result * x) % c = [(result % c) * (x % c)] % c`


```cpp
    a = (a * a) % c;
```

지수를 제곱의 나머지값으로 갱신했기 때문에 지수를 나누기 2를 한다
`(x * x) % c = [(x % c) * (x % c)] % c`
