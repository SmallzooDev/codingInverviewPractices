# Review
---

```cpp
#include <climits>
int final_result = INT_MAX;
```
INT_MAX 기억 안났음

```cpp
if (get_chicken_length(tmp) >= final_result) {
    return;
}
```
back_tracking 조기 종료 가능했음

```cpp
struct Point {
    int y, x;
};
vector<Point> chicken_point;
vector<Point> house_pont;
```
아무리봐도 나는 struct로 가독성을 높여놓는게 나은 것 같음
