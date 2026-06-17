# LeetCode 35-Search Insert Position

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 35
- **Problem Title:** Search Insert Position
- **Problem Link:** https://leetcode.com/problems/search-insert-position/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

## 2. Problem Statement in My Own Words
給定一個已排序（升序）的整數陣列 nums 和一個目標值 target。

請回傳 target 在陣列中的索引位置：
- 如果存在 → 回傳其 index
- 如果不存在 → 回傳它應該插入的位置（保持排序）

### 輸入
    一個升序排序的陣列 nums
    一個整數 target
###　輸出
    target 的 index 或插入位置
### 主要限制與規則
- 陣列是升序排序
- 需使用 O(log n) 或 O(n) 解法皆可
- 若不存在 target，需回傳「應插入的位置」
### 核心任務
    找到target 在 sorted array 中的位置（或插入點）

## 3. Thinking Logic and Solution Strategy
### 最初想法

- 直接線性掃描
- 找到第一個 >= target 的位置

### 最終策略
利用 binary search：
1. 設定 left / right
2. 找 mid
3. 比較 nums[mid] 與 target
4. 收斂搜尋範圍
5. 最後 left 即為插入位置


## 4. Pseudocode
```text
START

left = 0, right = n - 1

WHILE left <= right:
    mid = (left + right) / 2

    IF nums[mid] == target:
        return mid

    ELSE IF nums[mid] < target:
        left = mid + 1

    ELSE:
        right = mid - 1

return left

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};
```
**Why it works:**

- 使用 binary search
- 每次排除一半搜尋區間
- 若找不到 target：
    - left 會停在「應插入位置」
- 保證時間複雜度 O(log n)

### Reflection
- What challenges did you face?
    - 
- How would you improve this solution?
    - 多練習 lower_bound / upper_bound 類題目
- What did you learn?
    - 熟練 binary search\
    - binary search 不只是找值，也可以找「位置」