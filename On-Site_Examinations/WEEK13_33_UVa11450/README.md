
# UVa 11450 - Wedding shopping
## Problem Description
你有預算 M，想要購買 C 種不同的衣服。每種衣服有若干種不同的款式與價格。你必須從每一種衣服中恰好選擇一件購買，使得總花費最大，但不能超過預算 M。如果無法每種衣服都買到一件，則輸出 no solution。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2445)

## Learning Objectives
- [ ] 學會使用二維布林陣列記錄「可行狀態」
- [ ] 
## Solution Approach

### Algorithm Logic
1. 建立一個二維bool陣列 dp[i][j]。
    - i 代表目前考慮到第 i 種衣服。
    - j 代表目前累積花費的金額。
    - dp[i][j] = true 代表「買了前 i 種衣服後，總共花費 j 元」是可行的。
2. 讀入第 0 種衣服的所有價格，只要價格 p <= M，就把 dp[0][p] 設為 true。
3. 對於第 i 種衣服（從 1 到 C-1）：
    - 遍歷上一次可能的花費金額 j（即 dp[i-1][j] == true 的狀態）。
    - 遍歷第 i 種衣服的所有款式價格 p。
    - 如果 j + p <= M（沒超出預算），則將新的狀態標記為可行：dp[i][j + p] = true。
4. 檢查最後一種衣服（第 C-1 種）那一列。從最大預算 M 往下倒著找，第一個為 true 的金額就是答案。如果找回 0 都沒有任何 true，代表無解。

### Key Insights
- 關心「目前花掉多少錢」，而不是「買了哪一件衣服」。
## Code Structure
```cpp

#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    if (cin >> n) {
        while (n--) {
            int m, c;
            cin >> m >> c;

            // price[i] 儲存第 i 種衣服的所有可能價格
            vector<vector<int>> price(c);
            for (int i = 0; i < c; i++) {
                int k;
                cin >> k;
                price[i].resize(k);
                for (int j = 0; j < k; j++) {
                    cin >> price[i][j];
                }
            }

            // dp[i][j] 表示考慮到第 i 種衣服時，總花費 j 元是否可行
            vector<vector<bool>> dp(c, vector<bool>(m + 1, false));

            // 1. 初始化第一種衣服 (i = 0)
            for (int p : price[0]) {
                if (p <= m) {
                    dp[0][p] = true;
                }
            }

            // 2. 開始動態規劃
            for (int i = 1; i < c; i++) {       // 遍歷每一種衣服
                for (int j = 0; j <= m; j++) {  // 遍歷前一次所有可能的花費
                    if (dp[i - 1][j]) {         // 如果前一次花費 j 元是可行的
                        for (int p : price[i]) { // 遍歷當前衣服的所有款式價格
                            if (j + p <= m) {
                                dp[i][j + p] = true; // 新的花費總額可行
                            }
                        }
                    }
                }
            }

            // 3. 從最大預算 M 開始倒著找答案
            int ans = -1;
            for (int j = m; j >= 0; j--) {
                if (dp[c - 1][j]) {
                    ans = j;
                    break;
                }
            }
            
            if (ans == -1) {
                cout << "no solution" << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
    return 0;
}
```
[source code](./src/s1133343-UVa11450.cpp)

## Complexity Analysis
- **Time Complexity:** O(CxMxK)
- **Space Complexity:** O(CxM)

## Notes & Reflection
- What challenges did you face?
    - 邏輯想好 還沒想好怎麼寫 
- How would you improve this solution?
    - 
- What did you learn?
    - 
    - 

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials
