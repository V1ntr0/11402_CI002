# LeetCode 414 - Third Maximum Number

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 414
- **Problem Title:** Third Maximum Number
- **Problem Link:** https://leetcode.com/problems/third-maximum-number/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個整數陣列 nums。
    
### 輸出
一個整數，代表該陣列中排序後「第三大」的相異數字。如果第三大的相異數字不存在，則回傳該陣列中的「最大」數字。
    
### 主要限制與規則
- 所謂的「第一大、第二大、第三大」必須是相異的數字（例如 [2, 2, 3, 1] 的第一大是 3，第二大是 2，第三大是 1）。
- 如果相異數字不足三個（例如只有一或兩個），必須回傳最大值。

### 核心任務
在排除重複數字的情況下，準確定位陣列中第三大的數，若無則回傳最大值。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 先將整個陣列進行排序，這樣一來最大的數字就會集中在陣列的尾端。
- 接著從陣列的尾端（最大值）開始往前走訪，利用變數記錄當前數字，只有當遇到「不同的數字」時才將計數器加 1，以此過濾掉重複的值。


### 最終策略
1. 對 nums 進行由小到大的排序。
2. 初始化計數器 count = 1，並將 prev 設為陣列的最後一個元素（即最大值）。
3. 從倒數第二個元素開始往前遍歷陣列。
4. 遇到與 prev 不同的數字時，更新 count 與 prev。當 count 達到 3，立即回傳該數字。
5. 若迴圈結束後仍未找到第三大數字，則回傳最大值。


## 4. Pseudocode
```text
START
1. Sort nums in ascending order
2. Initialize count = 1
3. Initialize prev = nums[nums.size() - 1]
4. FOR i from nums.size() - 2 down to 0:
       IF nums[i] != prev THEN
           count = count + 1
           prev = nums[i]
       END IF
       IF count == 3 THEN
           RETURN prev
       END IF
5. RETURN nums[nums.size() - 1]
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int prev = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] != prev) { // 遇到不同數字
                count++;
                prev = nums[i];
            }
            if (count == 3) return prev; // 找到第三大
        }

        return nums[nums.size() - 1]; // 不到第三大 → 回傳最大
    }
};
```
**Why it works:**
- 排序後由後往前：確保我們能直接由大到小依次檢視數值。
- 重複值過濾：透過 nums[i] != prev 的條件，成功跳過了陣列中相鄰且相同的數字，確保 count 只計算不重複的有效排名。
- 安全的回傳機制：當陣列相異元素不足三個，迴圈跑完也不會觸發 count == 3，最後直接安全地回傳陣列尾端的最大值。

### Reflection
- What challenges did you face?
    - 需要細心處理重複元素對名次的影響。本解法利用排序與相鄰比較成功化解。
- How would you improve this solution?
    - 本解法的時間複雜度為排序的 O(n log n)。若想優化，可以使用三個變數或大小為 3 的集合（set）來動態維護前三大，將時間複雜度降到 O(n)。
- What did you learn?
    - 學會了在要求相異排名的題目中，利用「排序 + 倒序指針去重」的技巧來精準控制名次的累加。