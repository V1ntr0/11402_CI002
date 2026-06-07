# UVa 12405 - Scarecrow
## Problem Description
給定一塊長度為 n 的農田，以字串表示：

'.'：需要被保護的土地
'#'：已經無法種植的土地

一個稻草人可以覆蓋連續三格位置：

自己所在的位置
左邊一格
右邊一格

求最少需要放置多少個稻草人，才能覆蓋所有 '.'。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836)

## Learning Objectives
- [ ] Greedy Algorithm
## Solution Approach

### Algorithm Logic
1. 讀入測試資料筆數 T
2. 對每筆測試資料讀入 n 與農田字串 field
3. 從左到右掃描農田
4. 當遇到 '.' 時：
    - 必須放置一個稻草人
    - 將稻草人數量加一
    - 直接跳過接下來三格（i += 3）
5. 若遇到 '#' 則繼續往右掃描
6. 輸出最少稻草人數量
### Key Insights
- 若目前位置是 '.'，最佳策略是在此區域放置一個稻草人，使其一次覆蓋最多三格。
- 放置稻草人後，這三格一定都已被處理，因此可以直接跳到下一個未覆蓋的位置。
## Code Structure
```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    for (int i = 1; i <= T; i++) {
        int n;
        string field;
        cin >> n >> field;

        int scarecrows = 0;
        for (int i = 0; i < n; ) {
            if (field[i] == '.') {
                scarecrows++;
                i += 3;
            }
            else {
                i++;
            }
        }

        cout << "Case " << i << ": " << scarecrows << endl;
    }
    return 0;
}

```
[source code](./src/s1133343-UVa12405.cpp)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 思考要判斷'.'還是'#'
- How would you improve this solution?
    - 
- What did you learn?
    - 貪心法常見策略：每一步都盡可能覆蓋最多的需求。
    - 適當地跳過已處理區域可以降低實作複雜度。

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials