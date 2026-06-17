# LeetCode 56 - Merge Intervals

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 56
- **Problem Title:** Merge Intervals
- **Problem Link:** https://leetcode.com/problems/merge-intervals/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個二維整數陣列 `intervals`，其中 `intervals[i] = [start_i, end_i]` 代表一個閉區間。
    
### 輸出
一個合併後的二維整數陣列，其中所有重疊的區間都已經被合併，且涵蓋了輸入中所有的原始區間。
    
### 主要限制與規則
- 如果兩個區間有交集、相交、或者一個剛好接在另一個邊界上（例如 `[1, 3]` 和 `[3, 4]`），它們就必須被合併為一個大區間（變成 `[1, 4]`）。
- 輸入的區間順序一開始是**無序**的。

### 核心任務
在處理可能重疊的區間時，先透過排序建立先後順序，再利用貪婪（Greedy）思想，動態比對當前區間與前一個已處理區間的邊界關係，決定是要「合併擴展」還是「開啟新區間」。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 如果直接對無序的區間進行兩兩比對，會因為區間分布太雜亂而無從下手，時間複雜度也會極高。
- 既然要看誰和誰重疊，最好的方法就是**先按照區間的起點（`start`）由小到大排序**。排序之後，所有可能發生重疊的區間就會在陣列中相鄰出現。


### 最終策略
1. 建立一個二維陣列 `ans` 用來存放最終合併後的結果。
2. 對 `intervals` 進行排序。C++ 對 `vector<vector<int>>` 的預設排序規則是先比第一個元素（即起點 `start`），若相同再比第二個元素（即終點 `end`）。這完全符合我們的需求。
3. 使用一個範圍 `for` 迴圈依序遍歷排序後的每個區間 `interval`：
   - **情況一：無需合併。** 如果 `ans` 目前是空的，或者 `ans` 裡面最後一個區間的終點 `ans.back()[1]` 嚴格小於當前區間的起點 `interval[0]`，說明兩者完全沒有重疊。此時直接將 `interval` 推入 `ans` 中。
   - **情況二：發生重疊，進行合併。** 否則（即當前區間的起點 $\le$ 前一個區間的終點），說明兩者有重疊空間。此時我們不需要推入新區間，而是直接修改 `ans.back()[1]`（前一個區間的終點），將其更新為 `max(ans.back()[1], interval[1])`，藉此把當前區間融合進去。
4. 走訪結束後，`ans` 內即為完全合併且不重疊的區間集合。


## 4. Pseudocode
```text
START
1. Initialize an empty 2D array ans
2. Sort intervals in ascending order based on their start times
3. FOR each interval IN intervals:
       IF ans is empty OR ans.back()[1] < interval[0] THEN
           ans.push_back(interval)
       ELSE
           ans.back()[1] = max(ans.back()[1], interval[1])
       END IF
   END FOR
4. RETURN ans
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (auto& interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};
```
**Why it works:**
- **排序奠定線性基礎：** 排序後的區間具備了起點單調遞增的特性（$A_{\text{start}} \le B_{\text{start}}$），這意味著我們只需要將注意力放在 `ans.back()` 與目前區間的關係上，而不需要回头去檢查更前面的區間，成功將問題簡化。
- **完美的 `max` 涵蓋：** 當發生合併時，之所以要取 `max(ans.back()[1], interval[1])`，是為了完美涵蓋「區間完全包含」的情況（例如 `[1, 5]` 和 `[2, 4]` 合併後仍為 `[1, 5]`）。
- **極佳的複雜度表現：** 主要的時間消耗在於排序的 $O(n \log n)$，後續的合併走訪只需要單趟線性掃描 $O(n)$。總時間複雜度為 $O(n \log n)$，空間複雜度除輸出空間外為 $O(1)$ 或 $O(\log n)$（取決於排序演算法的實作）。

### Reflection
- What challenges did you face?
    - 理解「區間完全包含」與「部分重疊」是本題的關鍵。一開始如果不小心只寫了 `ans.back()[1] = interval[1]`，在遇到像是 `[[1,4],[2,3]]` 這樣的測資時，終點就會被錯誤地縮小為 3。使用 `max` 成功解決了這個潛在錯誤。
- How would you improve this solution?
    - 當前解法在時間與空間複雜度上都已經達到了理論上的最優解，程式碼利用 `ans.back()` 進行原地更新也顯得非常精煉。
- What did you learn?
    - 掌握了區間問題的核心：**先排序（Sort），再用貪婪策略（Greedy）配對滑動。** 