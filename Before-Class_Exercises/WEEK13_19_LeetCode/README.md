# LeetCode 64 - Minimum Path Sum

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 64
- **Problem Title:** Minimum Path Sum
- **Problem Link:** https://leetcode.com/problems/minimum-path-sum/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個包含非負整數的 $m \times n$ 網格 `grid`。
    
### 輸出
一個整數，代表從網格左上角走到右下角的所有路徑中，數字相加總和「最小」的那條路徑數字和。
    
### 主要限制與規則
- 機器人一開始在左上角 `(0, 0)`，目的地在右下角 `(m-1, n-1)`。
- 在任何時間點，**只能向下或者向右**移動一步。
- 網格內所有數字皆為非負整數（$\ge 0$）。

### 核心任務
在只能向右或向下的移動限制下，找出起點到終點的「最小權重路徑和」，本質上是在所有分支路徑中尋找最佳局部解。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 此題與「Unique Paths」非常相似，同樣可以用遞迴走訪（DFS）列舉向右與向下的所有走法，並紀錄路徑總和以找出最小值。
- 但因為有大量重複子問題的走訪，純遞迴會導致 TLE。
- 要抵達某個格子 `(i, j)`，若已知從「上方格子」與「左邊格子」過來的最小路徑和，我們只需從中挑選一個較小的，再加上當前格子的數值即可。這具有最優子結構特性，適合使用**動態規劃（Dynamic Programming）**。


### 最終策略
1. 為了追求極致的空間效率，我們不另外宣告 `dp` 陣列，而是**直接在輸入的二維陣列 `grid` 上進行原地（In-place）修改**，讓 `grid[i][j]` 直接代表走到位置 `(i, j)` 的最小路徑總和。
2. 以雙重迴圈遍歷整張網格，針對不同的格子位置，其狀態轉移可以分為四種情況：
   - **左上角起點 `(i == 0 && j == 0)`：** 維持原數值，不作任何變動。
   - **第一列 `(i == 0)`：** 機器人只能從其左邊格子 `(i, j-1)` 一路向右走過來。因此狀態轉移為：`grid[i][j] += grid[i][j-1]`。
   - **第一欄 `(j == 0)`：** 機器人只能從其上方格子 `(i-1, j)` 一路向下走過來。因此狀態轉移為：`grid[i][j] += grid[i-1][j]`。
   - **一般內部格子：** 可以從左邊 `(i, j-1)` 或上面 `(i-1, j)` 抵達。為了獲得最小總和，應選擇兩者中較小的值疊加：`grid[i][j] += min(grid[i-1][j], grid[i][j-1])`。
3. 當網格遍歷結束，右下角 `grid[m-1][n-1]` 的數值即為最終答案。


## 4. Pseudocode
```text
START
1. m = grid.size(), n = grid[0].size()
2. FOR i from 0 to m - 1:
       FOR j from 0 to n - 1:
           IF i == 0 AND j == 0 THEN
               CONTINUE
           ELSE IF i == 0 THEN
               grid[i][j] = grid[i][j] + grid[i][j - 1]
           ELSE IF j == 0 THEN
               grid[i][j] = grid[i][j] + grid[i - 1][j]
           ELSE
               grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1])
           END IF
       END FOR
3. RETURN grid[m - 1][n - 1]
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                else if (i == 0)
                    grid[i][j] += grid[i][j - 1];

                else if (j == 0)
                    grid[i][j] += grid[i - 1][j];

                else
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};
```
**Why it works:**
- **原地修改（In-place）節省空間：** 由於當前格子 `(i, j)` 只依賴於左方與上方已經算好的最優解，且舊有的 `grid[i][j]` 數值在參與加法運算後就不再需要。直接原地覆寫可以把額外空間複雜度優化至最完美的 $O(1)$。
- **嚴謹區分邊界狀態：** 對於最上面一列與最左邊一欄採取了獨立特判，確保不會發生 `i-1` 或 `j-1` 的陣列索引越界錯誤（Out of bounds），邏輯非常健全。
- **最優子結構的直接映射：** 透過 `min(grid[i-1][j], grid[i][j-1])`，讓每個內部格子在計算當下，都自動繼承了先前步驟衍生過來的全域最優解。

### Reflection
- What challenges did you face?
    - 邊界條件的處理是這類題目最核心的細節。雖然可以透過宣告一個比原陣列大一圈、初始化為無限大（`INT_MAX`）的緩衝陣列來統一內部格子的寫法，但直接在原陣列上透過 `if-else` 分流處理更為簡潔且節省空間。
- How would you improve this solution?
    - 當前的方案在時間複雜度 $O(m \times n)$ 且空間複雜度 $O(1)$ 上，已經是實作中的最優解，沒有任何需要改進的空間。
- What did you learn?
    - 體會到若題目允許修改輸入參數，利用「原地覆寫」來替代開闢額外的 `dp` 表格，是壓榨與優化記憶體空間效率（達到 $O(1)$）的絕佳手法。