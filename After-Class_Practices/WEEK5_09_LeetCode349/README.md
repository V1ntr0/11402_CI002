# LeetCode 349-Intersection of Two Arrays

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 349
- **Problem Title:** Intersection of Two Arrays
- **Problem Link:** https://leetcode.com/problems/intersection-of-two-arrays/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words
給定兩個整數陣列 nums1 和 nums2，請找出它們的「交集」，並且結果中的元素：
- 不可以重複
- 順序不重要

### 輸入
    兩個整數陣列 nums1, nums2
###　輸出
    一個陣列，包含兩個陣列的交集（不重複）
### 主要限制與規則
- 只保留「有出現在兩個陣列」的數字
- 結果不能有重複
- 輸出順序不限
### 核心任務
    找出：nums1 ∩ nums2（set intersection）

## 3. Thinking Logic and Solution Strategy
### 最初想法

- 雙層迴圈暴力比對
- 排序後再比較



### 最終策略
使用 set（或 unordered_set）來解決：
1. 先把 nums1 放進 set
2. 遍歷 nums2
3. 如果元素在 set 中 → 加入答案
4. 使用另一個 set 避免重複


## 4. Pseudocode
```text
START

set1 = set(nums1)
resultSet = empty set

FOR each num in nums2:
    IF num in set1:
        add num to resultSet

return resultSet as vector

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
```
**Why it works:**

- set1 用來快速查找 nums1 的元素（O(1)）
- 遍歷 nums2 時只做查找，不需要雙層迴圈
- result 自動去重
- 最後轉成 vector 回傳
- 

### Reflection
- What challenges did you face?
    - 一開始容易用暴力雙迴圈思考，沒有立即想到 set 優化
- How would you improve this solution?
    - 
- What did you learn?
    - set 是處理「查找 + 去重」的標準工具