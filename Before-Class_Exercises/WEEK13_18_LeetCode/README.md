# LeetCode 62 - Unique Paths

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 62
- **Problem Title:** Unique Paths
- **Problem Link:** https://leetcode.com/problems/unique-paths/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
兩個整數 `m` 和 `n`，代表一個 $m \times n$ 的網格（Grid）大小。
    
### 輸出
一個整數，代表機器人從網格的左上角走到右下角，總共存在多少種「唯一不同的路徑」。
    
### 主要限制與規則
- 機器人一開始位於左上角（位置 `(0, 0)`），目標是要走到右下角（位置 `(m-1, n-1)`）。
- 機器人在任何時間點，**只能向下或者向右**移動一步。
- 網格大小 $m$ 與 $n$ 的範圍在 `[1, 100]` 之間，且題目保證最終答案小於等於 $2 \times 10^9$（可用標準整數儲存）。

### 核心任務
找出在只能向右與向下的移動限制下，從起點到終點的所有不重複走法總數。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 可以使用遞迴（DFS）去窮舉機器人每一步要向右還是向下，直到走到終點就將路徑數加 1。
- 然而，這種純遞迴的暴力法會包含大量的「重複子問題」計算，時間複雜度會呈現指數級別 $O(2^{m+n})$，必定會發生逾時（TLE）。
- 由於到達某個格子的方法只取決於它的「左邊格子」與「上方格子」，因此非常適合使用**動態規劃（Dynamic Programming）**來記錄中間狀態。


### 最終策略
1. 建立一個大小為 $m \times n$ 的二維狀態陣列 `dp`，其中 `dp[i][j]` 代表從起點走到位置 `(i, j)` 的唯一路徑總數。
2. **邊界與初始化：** 對於網格的第一列（`i = 0`）與第一欄（`j = 0`），因為機器人只能往右或往下，所以要走到這兩條直線上的任何格子，都各自只有「一路向右」或「一路向下」這 1 種走法。因此將整張 `dp` 陣列直接全部初始化為 `1`。
3. **狀態轉移：** 從 `(1, 1)` 開始以雙重迴圈遍歷其餘所有的格子。
4. 對於任意格子 `(i, j)`，走到該處的方法只有兩種可能：從上面那一格 `(i-1, j)` 往下走，或者從左邊那一格 `(i, j-1)` 往右走。
5. 狀態轉移方程式即為：`dp[i][j] = dp[i-1][j] + dp[i][j-1]`。
6. 最終，右下角終點的 `dp[m-1][n-1]` 便是我們要的答案。


## 4. Pseudocode
```text
START
1. Initialize a 2D array dp of size m x n with all elements set to 1
2. FOR i from 1 to m - 1:
       FOR j from 1 to n - 1:
           dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
       END FOR
3. RETURN dp[m - 1][n - 1]
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 1));//建立一個 m x n 的二維陣列，全部初始化成 1

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//上面格子 + 左邊格子
            }
        }

        return dp[m - 1][n - 1];
    }
};
```
**Why it works:**
- **空間換時間的完美應用：** 利用二維表格將先前已經計算出來的子路徑數保存起來。當計算到新格子時，只需要花費 $O(1)$ 的常數時間將左邊與上面的已知結果相加即可，避免了重複運算。
- **簡潔的初始化巧思：** 直接將整張表格初始化為 1，既完成了第一列與第一欄的邊界條件設定（`dp[0][j] = 1`, `dp[i][0] = 1`），又精簡了程式碼行數，無須再單獨寫迴圈處理邊界。
- **優良的複雜度表現：** 雙重迴圈剛好將整張網格完整掃描一遍，時間複雜度為極佳的 $O(m \times n)$，空間複雜度為二維陣列所佔用的 $O(m \times n)$。

### Reflection
- What challenges did you face?
    - 本題屬於動態規劃的經典入門題，邏輯轉換相對直覺。主要在於確認邊界狀態（第一列與第一欄不應在雙重迴圈中被覆蓋，且必須維持為 1）的細節。
- How would you improve this solution?
    - 可以優化為一維陣列空間，空間複雜度能成功被壓縮至 $O(n)$。
    - 這題在本質上也可以直接利用組合數學的排列組合公式 $C^{m+n-2}_{m-1}$ 在 $O(\min(m, n))$ 的時間與 $O(1)$ 的空間內求解。
- What did you learn?
    - 深入理解了動態規劃（DP）中網格路徑問題的經典轉移邏輯，體會到如何透過「將當前狀態拆解為最後一步的可能分支之和」來快速建立網格狀態方程式。