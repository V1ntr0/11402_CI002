# LeetCode 33-Search in Rotated Sorted Array

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 33
- **Problem Title:**  Search in Rotated Sorted Array
- **Problem Link:** https://leetcode.com/problems/search-in-rotated-sorted-array/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words
給定一個已經排序過但被「旋轉」的陣列 nums，以及一個目標值 target。

旋轉意思是：
原本：1 2 3 4 5 6 7
可能變成：4 5 6 7 1 2 3

請找出 target 在陣列中的 index，如果不存在則回傳 -1。

### 輸入
    一個旋轉過的升序陣列 nums
    一個整數 target
###　輸出
    必須在 O(log n) 時間內完成（暗示 binary search）
### 主要限制與規則
- 陣列原本是升序
- 被 pivot 旋轉過一次
- 必須在 O(log n) 時間內完成（暗示 binary search）
### 核心任務
    在「部分有序」的陣列中找到 target：rotated sorted array + binary search

## 3. Thinking Logic and Solution Strategy
### 最初想法

- 直接線性搜尋（O(n)）
- 或先找 pivot 再 binary search

### 最終策略
每次 mid 都可以判斷：
- 左半邊是否有序
- 右半邊是否有序
然後決定 target 在哪一邊。

搜尋邏輯
1. 判斷哪一邊是 sorted
2. 看 target 是否在該區間
3. 決定 left / right 移動方向
4. 重複直到找到或結束

## 4. Pseudocode
```text
START

left = 0, right = n - 1

WHILE left <= right:
    mid = (left + right) / 2

    IF nums[mid] == target:
        return mid

    IF left half is sorted:
        IF target in left half:
            search left
        ELSE:
            search right

    ELSE (right half is sorted):
        IF target in right half:
            search right
        ELSE:
            search left

return -1

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
```
**Why it works:**

- rotated array 仍然保有「一半一定是 sorted」
- 每次 binary search 都可以排除一半區間
- 利用 sorted half 判斷 target 是否在該區間
- 保證 O(log n)

### Reflection
- What challenges did you face?
    - 容易混亂 left/right 更新條件
- How would you improve this solution?
    - 多練習 pivot / rotation 類型題目
- What did you learn?
    - 