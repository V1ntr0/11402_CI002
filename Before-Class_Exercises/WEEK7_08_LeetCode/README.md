# LeetCode 704 - Binary Search

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 704
- **Problem Title:** Binary Search
- **Problem Link:** https://leetcode.com/problems/binary-search/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個已排序好（升序）的整數陣列 `nums`，以及一個欲尋找的目標值 `target`。
    
### 輸出
一個整數。如果 `target` 存在於陣列中，回傳它的索引（Index）；如果不存在，則回傳 `-1`。
    
### 主要限制與規則
- 陣列中的所有整數都是獨一無二的（相異）。
- 必須設計一個時間複雜度為 $O(\log n)$ 的演算法。

### 核心任務
利用陣列已排序的特性，在對數時間內高效判斷目標值是否存在並找出其位置。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 若使用線性搜尋法（由前往後一個個找），時間複雜度會是 $O(n)$，無法滿足題目 $O(\log n)$ 的要求。
- 既然陣列已經由小到大排好，可以直接使用「二分搜尋法」（Binary Search），每次切半排除不可能的區間。


### 最終策略
1. 初始化雙指針，`left` 指向陣列開頭（`0`），`right` 指向陣列結尾（`nums.size() - 1`）。
2. 當 `left <= right` 的條件成立時，持續進行循環。
3. 每次計算中點 `mid = left + (right - left) / 2`，避免直接相加導致整數溢位（Overflow）。
4. 比較 `nums[mid]` 與 `target`：
   - 若相等，代表找到了，立即回傳 `mid`。
   - 若 `nums[mid] < target`，代表目標值在中點右方，將左邊界縮小，令 `left = mid + 1`。
   - 若 `nums[mid] > target`，代表目標值在中點左方，將右邊界縮小，令 `right = mid - 1`。
5. 若迴圈結束仍未找到，代表 `target` 不存在，回傳 `-1`。


## 4. Pseudocode
START
1. Initialize left = 0, right = nums.size() - 1
2. WHILE left <= right:
       mid = left + (right - left) / 2
       IF nums[mid] == target THEN
           RETURN mid
       ELSE IF nums[mid] < target THEN
           left = mid + 1
       ELSE
           right = mid - 1
       END IF
3. RETURN -1
END

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
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};
```
**Why it works:**
- **精準的範圍控制（閉區間）：** 使用 `while (left <= right)` 搭配 `mid + 1` 與 `mid - 1`，屬於標準的閉區間 `[left, right]` 寫法。當 `left == right` 時仍會檢查最後一個元素，保證不會漏掉任何數字。
- **防止溢位（Overflow）：** 使用 `mid = left + (right - left) / 2` 而非 `(left + right) / 2`，能有效防止當 `left` 與 `right` 的數值極大時相加超出 `int` 的最大範圍。
- **對數級別的搜尋速度：** 每次比較都能將搜尋範圍砍半，使得時間複雜度穩定保持在 $O(\log n)$。

### Reflection
- What challenges did you face?
    - 二分搜尋法最容易在邊界條件（如 `while` 裡該用 `<` 還是 `<=`，以及邊界更新時要不要 `+/- 1`）寫錯導致無窮迴圈。本次採用閉區間邏輯，邊界處理清晰明瞭。
- How would you improve this solution?
    - 當前解法已是時間 $O(\log n)$ 與空間 $O(1)$ 的最優標準解，無需進一步優化。
- What did you learn?
    - 複習了最經典的二分搜尋法核心模板，並再次驗證了在處理已排序數據的搜尋時，二分法在效能上的巨大優勢。