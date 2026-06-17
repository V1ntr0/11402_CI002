# LeetCode 228 - Summary Ranges

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 228
- **Problem Title:** Summary Ranges
- **Problem Link:** https://leetcode.com/problems/summary-ranges/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個已經排序好（升序）且不包含重複數字的整數陣列 `nums`。
    
### 輸出
一個字串陣列 `ans`，代表將連續數字分組後的範圍摘要清單。
    
### 主要限制與規則
- 只要數字是連續的（即相鄰兩數差值為 1），就必須將它們歸類在同一個區間內。
- 區間格式：
  - 如果該區間只有單個數字 `a`，字串格式為 `"a"`。
  - 如果該區間包含多個連續數字，從 `a` 到 `b`，字串格式為 `"a->b"`。
- 輸入陣列可能為空，且數值範圍涵蓋整個標準 32 位元有號整數（`INT_MIN` 到 `INT_MAX`）。

### 核心任務
利用雙指針或雙重迴圈，高效地找出陣列中的所有連續片段，並將其格式化為對應的區間字串。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 走訪陣列，只要發現當前數字與前一個數字不連續，就代表上一個區間結束，需要結算並開啟新區間。
- 這種做法需要小心維護區間的起點與終點，並且在迴圈結束後還要額外補上一筆最後區間的結算，邊界特判較多。


### 最終策略
1. 採用**雙指針（或雙重迴圈內層移動）**的策略，讓指標控制更為簡潔，且能自然處理結算。
2. 外層迴圈使用指標 `i` 指向當前區間的起點，並記錄數值 `start = nums[i]`。此時不要在 `for` 的第三個條件寫 `i++`，而是改由內層動態控制。
3. 內層使用指標 `j` 從 `i` 開始。開啟一個 `while` 迴圈往後探索：
   - 條件為 `j + 1 < n`（防越界）且 `nums[j + 1] - nums[j] == 1`（判斷是否連續）。
   - 為了防範整數溢位，將兩數相減的過程強制轉型為 `(long long)`。
   - 若滿足連續條件，則將 `j++`，代表區間的終點不斷往後延伸。
4. 當 `while` 迴圈停止時，`j` 正好停在當前連續區間的最後一個元素：
   - 若 `i == j`，說明此區間只有一個數字，推入 `to_string(start)`。
   - 若 `i != j`，說明是多元區間，推入 `to_string(start) + "->" + to_string(nums[j])`。
5. 結算完後，直接將 `i` 跳到 `j + 1`，作為下一個區間的起點，繼續重複上述步驟。


## 4. Pseudocode
```text
START
1. Initialize empty string vector ans
2. Initialize n = nums.size(), i = 0
3. WHILE i < n:
       start = nums[i]
       j = i
       WHILE j + 1 < n AND (long long)nums[j + 1] - nums[j] == 1:
           j = j + 1
       END WHILE
       IF i == j THEN
           ans.push_back(to_string(start))
       ELSE
           ans.push_back(to_string(start) + "->" + to_string(nums[j]))
       END IF
       i = j + 1
   END WHILE
4. RETURN ans
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        for (int i = 0; i < n; ) {
            int start = nums[i];
            int j = i;

            while (j + 1 < n && (long long)nums[j + 1] - nums[j] == 1) {
                j++;
            }

            if (i == j) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(nums[j]));
            }

            i = j + 1;
        }

        return ans;
    }
};
```
**Why it works:**
- **內外層指針的自然結算：** 藉由 `i = j + 1` 的滾動更新，外層迴圈會自動跳過已經被包進區間的連續元素。這種「區間一次吃滿」的寫法，完美避開了傳統單指針在迴圈結束後需要「補刀結算最後一筆」的麻煩。
- **防止溢位（Overflow Flag）：** 題目中的數值可能包含 `INT_MIN` 或 `INT_MAX`。當相鄰兩數如 `-1` 與 `INT_MAX` 或相減可能觸發溢位時，程式碼中使用 `(long long)nums[j + 1] - nums[j]` 提前拉高資料型態的精確度，確保減法比較安全無誤。
- **一趟線性掃描：** 雖然存在內外雙重迴圈，但因為 `i` 是直接繼承 `j + 1`，陣列中的每個元素在整體程式執行的過程中其實**只被檢視了一次**，時間複雜度是完美的線性 $O(n)$。

### Reflection
- What challenges did you face?
    - 在處理整數相減時需要防範 Overflow。雖然也可以用 `nums[j + 1] == nums[j] + 1` 來判斷連續，但若 `nums[j]` 為 `INT_MAX`，加 1 一樣會溢位。本解法透過 `(long long)` 轉型作減法，非常安全。
- How would you improve this solution?
    - 當前的解法在時間複雜度 $O(n)$ 與額外空間複雜度 $O(1)$ 上已經是最優解，程式碼結構也極其精煉、好讀。
- What did you learn?
    - 掌握了在處理「連續區間分組 / 聚合（Grouping / Chunking）」的問題時，利用內層 `while` 一口氣將指針推到區間末端的雙指針版型。