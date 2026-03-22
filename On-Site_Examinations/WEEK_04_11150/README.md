
# UVa 11150 - Cola
## Problem Description
你一開始有 n 瓶可樂，每喝完一瓶會得到一個空瓶。

規則：

3 個空瓶可以換 1 瓶可樂
可以「借」1 個空瓶來多換一次（但只能借一次）

請問最多可以喝幾瓶可樂？ere. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2091)

## Learning Objectives
- [ ] 練習模擬瓶子交換過程
- [ ] 熟悉 while 迴圈應用

## Solution Approach

### Algorithm Logic
1. 不斷讀入 n
2. 初始化:
	- total = n（一開始就能喝的）
	- empty = n（空瓶數）
3. 當 empty >= 3：
	- 用 empty / 3 換新可樂，累加到 total
	- 更新 empty = empty % 3 + new_cola
4. 特殊情況：
	- 如果最後 empty == 2，可以借 1 瓶再喝一次 → total++
5. 輸出 total

### Key Insights
- 每次交換其實是：
	- 3 空瓶 → 1 可樂 → 1 空瓶
- 當剩 2 個空瓶時，可以「借 1 個」再多喝一次
## Code Structure
```cpp
#include <iostream>
using namespace std;
int main() {
    int N;
    while(cin >> N)
        cout << 3 * N / 2 << endl;
}
```
[source code](./src/s1133343-UVa11150-Bonus)
### 正常解法:
```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int total = n;
        int empty = n;

        while (empty >= 3) {
            int new_cola = empty / 3;
            total += new_cola;
            empty = empty % 3 + new_cola;
        }

        // 借一瓶的情況
        if (empty == 2) {
            total += 1;
        }

        cout << total << endl;
    }

    return 0;
}
```
## Complexity Analysis
- **Time Complexity:** O(log(n))
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 容易忽略「可以借一瓶」這個關鍵條件
- How would you improve this solution?
    - 練習更多「資源交換」類型題目
- What did you learn?
    - 如何處理「特殊條件」來讓答案最大化
    - UVA 常見的 EOF 輸入模式

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials