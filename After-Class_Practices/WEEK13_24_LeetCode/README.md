# LeetCode 1143 - Longest Common Subsequence

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1143
- **Problem Title:** Longest Common Subsequence
- **Problem Link:** https://leetcode.com/problems/longest-common-subsequence/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
兩個字串 `text1` 和 `text2`。
    
### 輸出
一個整數，代表這兩個字串的最長公共子序列（LCS）的長度。
    
### 主要限制與規則
- 子序列是指從原字串中刪除一些字元（也可以不刪除），在不改變剩下字元相對順序的情況下組成的新字串（例如 `"ace"` 是 `"abcde"` 的子序列，但 `"aec"` 不是，因為順序反了）。
- 字串長度範圍在 `[1, 1000]` 之間，只包含小寫英文字母。

### 核心任務
找出兩個字串中，在維持字元前後順序不變的前提下，最多能有多少個互相匹配的相同字元。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 如果用暴力法去窮舉 `text1` 的所有子序列，再去比對有沒有在 `text2` 出現，那時間複雜度會是恐怖的指數級，字串長度一長絕對跑不動。
- 當我們在比對兩個字串時，可以把問題縮小：先看各自的前幾個字元比對得怎麼樣，再根據最後一個字元是不是相同，來決定要怎麼累積長度。這種大問題可以拆成小問題的特性，很適合用**動態規劃（Dynamic Programming）**。


### 最終策略
1. 建立一個二維陣列 `dp`，大小為 `(m + 1) * (n + 1)`，其中 `m` 和 `n` 分別是兩字串的長度。
2. `dp[i][j]` 代表的意義是：`text1` 的前 `i` 個字元，跟 `text2` 的前 `j` 個字元，它們的最長公共子序列長度。
3. **初始化與邊界：** 當其中一個字串長度為 0 時（也就是 `i = 0` 或 `j = 0`），它們的公共子序列長度一定是 0。所以 `dp` 陣列的第一列和第一欄全部填 0（這也是為什麼陣列大小要多開一格）。
4. **狀態轉移邏輯：** 用雙重迴圈去填滿整張 `dp` 表格。
   - 如果當前比對的字元相同（即 `text1[i - 1] == text2[j - 1]`），代表找到了新的一對匹配，長度可以直接加 1。這個 1 要加在「各自還沒納入這兩個字元」的狀態上，也就是：`dp[i][j] = dp[i - 1][j - 1] + 1`。
   - 如果字元不相同，代表這兩個字元沒辦法同時配對。此時的長度就必須退一步，看是「不要 `text1` 的最後一個字元（`dp[i - 1][j]`）」比較長，還是「不要 `text2` 的最後一個字元（`dp[i][j - 1]`）」比較長，從中取最大值：`dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`。
5. 最終右下角的 `dp[m][n]` 就是我們要的答案。


## 4. Pseudocode
```text
START
1. m = text1.size(), n = text2.size()
2. Initialize a 2D array dp of size (m + 1) x (n + 1) with all zeros
3. FOR i from 1 to m:
       FOR j from 1 to n:
           IF text1[i - 1] == text2[j - 1] THEN
               dp[i][j] = dp[i - 1][j - 1] + 1
           ELSE
               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
           END IF
       END FOR
   END FOR
4. RETURN dp[m][n]
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 因為 dp 的指標是從 1 開始，對應到字串的索引要減 1
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 字母相同，左上角的值加 1
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 字母不同，取上面或左邊的最大值
                }
            }
        }

        return dp[m][n];
    }
};
```
**Why it works:**
- **空間對齊避開越界：** 把 `dp` 陣列的大小設為 `(m + 1) * (n + 1)`，讓第 0 列和第 0 欄當作緩衝。這樣當我們在算 `i - 1` 或 `j - 1` 的時候，絕對不會發生索引超出陣列範圍的錯誤。
- **邏輯覆蓋完整：** 轉移公式精準分類了兩種情況：相同時往左上角找並加 1，不同時往左和往上找最大值。這確保了不論字元是連續匹配還是中間有斷開，最優的長度資訊都能透過表格不斷傳遞下去。
- **時空複雜度很穩定：** 雙重迴圈各走訪一次字串長度，時間複雜度是 $O(m \times n)$。使用了一個二維矩陣，空間複雜度也是 $O(m \times n)$，在字串長度 1000 的限制下可以輕鬆通過。

### Reflection
- What challenges did you face?
    - 最容易卡住的地方是字串索引跟 `dp` 陣列索引的對應。因為 `dp` 表格多開了第 0 行來當邊界，所以 `dp[i][j]` 對應到的字串字元實際上是 `text1[i - 1]` 和 `text2[j - 1]`。如果把這兩個地方的 `-1` 弄混，算出來的字母對應就會完全錯位。
- How would you improve this solution?
    - 觀察一下公式會發現，每次在計算 `dp[i][j]` 時，只會用到「上一列（`i - 1`）」和「目前這一列（`i`）」的資料。所以我們根本不需要存下整張大表格，只需要開兩個一維陣列，甚至是一維陣列配一個暫存變數，就可以把空間複雜度從 $O(m \times n)$ 直接縮減到 $O(n)$。
- What did you learn?
    - 徹底弄懂了最經典的字串雙序列動態規劃（LCS問題）。學會了如何透過二維矩陣來比對兩個序列的關係，這套「相同就取左上角加 1，不同就取左和上最大值」的版型，是很多進階字串比對題目的重要基本功。