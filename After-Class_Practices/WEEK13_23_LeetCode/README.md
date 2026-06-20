# LeetCode 63 - Unique Paths II

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 63
- **Problem Title:** Unique Paths II
- **Problem Link:** https://leetcode.com/problems/unique-paths-ii/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個 $m \times n$ 的二維陣列 `obstacleGrid`，代表一張網格地圖。其中 `0` 代表空地，`1` 代表障礙物（不能走）。
    
### 輸出
一個整數，代表機器人避開所有障礙物，從左上角走到右下角總共有多少種「唯一不同的路徑」。
    
### 主要限制與規則
- 機器人只能**向下**或**向右**移動。
- 如果起點 `(0,0)` 或終點 `(m-1, n-1)` 本身就是障礙物 `1`，那根本連走都不用走，直接就是 0 種方法。
- 網格大小 $m$ 和 $n$ 的範圍在 `[1, 100]` 之間。

### 核心任務
在上一題 Unique Paths 的基礎上加上「障礙物」的限制。走到某個格子的方法一樣是「左邊格子」加「上方格子」，但如果那一格是障礙物，方法數就要強制作廢編成 0。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 這題跟 Unique Paths 很像，一樣可以用動態規劃（DP）來解。
- 準備一個同樣大小的 `dp` 陣列，`dp[i][j]` 代表走到該格子的路徑數。
- 如果地圖上那一格是 1，代表死路一條，走到那裡的方法數就是 0。
- 如果是 0，那就去抓左邊和上面的值加起來。


### 最終策略
1. 建立一個大小為 $m \times n$ 的二維陣列 `dp`，因為路徑數可能很大，保險起見我們用 `long long` 或大一點的型態，不過這題用 `int` 如果怕溢位可以用 `vector<vector<int>> dp(m, vector<int>(n, 0))` 處理（題目測資有保證答案在 int 範圍內）。一開始全部填 0。
2. **初始化起點：** 如果起點 `obstacleGrid[0][0] == 0`，那走到起點的方法數就是 `dp[0][0] = 1`；否則如果是 1 遇上障礙，直接回傳 0。
3. **初始化第一列和第一欄：**
   - 第一列的格子只能從左邊一路走過來。如果左邊走得通且當前格子不是障礙物，那方法數就是 1；一旦中間遇到一個障礙物，後面那一整列的格子機器人都去不了，方法數直接卡死變成 0。
   - 第一欄同理，只能從上面一路往下走。只要上面卡住或當前是障礙物，後面就全部都是 0。
4. **填滿剩下的格子：** 用雙重迴圈從 `(1, 1)` 開始走訪。
   - 如果 `obstacleGrid[i][j] == 1`，代表是障礙物，`dp[i][j] = 0`。
   - 如果是空地，那就是 `dp[i][j] = dp[i-1][j] + dp[i][j-1]`（上面格子的方法數 + 左邊格子的方法數）。
5. 最終右下角 `dp[m-1][n-1]` 就是答案。


## 4. Pseudocode
```text
START
1. m = obstacleGrid.size(), n = obstacleGrid[0].size()
2. IF obstacleGrid[0][0] == 1 THEN RETURN 0
3. Initialize a 2D array dp of size m x n with all zeros
4. dp[0][0] = 1
5. FOR i from 1 to m - 1:
       IF obstacleGrid[i][0] == 0 AND dp[i - 1][0] == 1 THEN dp[i][0] = 1
   END FOR
6. FOR j from 1 to n - 1:
       IF obstacleGrid[0][j] == 0 AND dp[0][j - 1] == 1 THEN dp[0][j] = 1
   END FOR
7. FOR i from 1 to m - 1:
       FOR j from 1 to n - 1:
           IF obstacleGrid[i][j] == 1 THEN
               dp[i][j] = 0
           ELSE
               dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
           END IF
       END FOR
   END FOR
8. RETURN dp[m - 1][n - 1]
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 如果起點就是障礙物，直接下課
        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // 起點出發算 1 種方法
        dp[0][0] = 1;

        // 初始化第一欄（最左邊那一條直線）
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) {
                dp[i][0] = 1;
            }
        }

        // 初始化第一列（最上面那一條直線）
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) {
                dp[0][j] = 1;
            }
        }

        // 開始填剩下的格子
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // 踩到障礙物方法數就是 0
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // 上面 + 左邊
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
```
**Why it works:**
- **障礙物直接斷路：** 只要地圖上那一格是 `1`，在 DP 陣列裡就強制作廢給它 `0`。這樣之後右邊和底下的格子在抓舊資料加總時，加到 `0` 就相當於自動忽略了這條走不通的死路，邏輯非常合理。
- **邊界傳導很安全：** 第一列和第一欄在初始化的時候，加上了 `dp[i-1][0] == 1` 或 `dp[0][j-1] == 1` 的檢查。這代表只要前面被障礙物切斷過，後面的格子就算本身是空地（`0`），也一輩子拿不到 1 了，完全符合機器人只能往右和往下的行為。
- **時間與空間很穩定：** 只要把地圖掃過一次就能算出答案，時間複雜度是 $O(m \times n)$。我們另外開了相同大小的 `dp` 表格，空間複雜度也是 $O(m \times n)$。

### Reflection
- What challenges did you face?
    - 這題最容易翻車的地方是第一列和第一欄的初始化。很多人習慣直接跟上一題一樣全部無腦填 1，但如果第一列的第 2 格是障礙物，那第 3 格跟第 4 格機器人這輩子是絕對走不到的（因為只能向右向下，沒辦法繞過障礙物再繞回來）。所以在初始化邊界時，必須確認「前一格走得通」才能繼續給 1。
- How would you improve this solution?
    - 既然我們每次算 `dp[i][j]` 只需要用到「目前這列的左邊那一格」跟「上一列的同一欄」，我們其實可以把二維陣列壓縮成一維的 `vector<int> dp(n, 0)`。甚至如果題目允許，直接在輸入的 `obstacleGrid` 上原地修改來存方法數，這樣就可以把額外的空間複雜度壓到最低的 $O(1)$。
- What did you learn?
    - 體會到在動態規劃的網格問題中，如何透過「給予特定格子 0 值」來代表斷路、死路與障礙物。只要狀態轉移公式設計得好，障礙物的特殊規則也會自然融入原本的加法邏輯中。