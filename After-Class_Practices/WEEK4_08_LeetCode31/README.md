# LeetCode 31-Next Permutation

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 31
- **Problem Title:** Next Permutation
- **Problem Link:** https://leetcode.com/problems/next-permutation/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/



## 2. Problem Statement in My Own Words
給定一個整數陣列 nums，請將它重新排列成「字典序中的下一個更大排列」。

如果不存在更大的排列（也就是已經是最大排列），則將它變成最小排列（升序）。

### 輸入
    一個整數陣列 nums
###　輸出
    修改後的陣列（in-place）
### 主要限制與規則
- 必須在原陣列上修改（O(1) 額外空間）
- 必須找到「下一個字典序排列」
- 如果沒有下一個排列 → 變成最小排列（排序）
### 核心任務
找出：
下一個比當前排列稍微大一點的排列

## 3. Thinking Logic and Solution Strategy
### 最初想法

一開始可能會想到：
- 直接列出所有排列（permutation）
- 排序後找到下一個
但這樣會有問題：
- 時間複雜度太高（O(n!)）
- 不符合 in-place 要求

### 最終策略

1. 從右往左找「第一個下降點」
    - 找到 nums[i] < nums[i+1]
2. 從右邊找「第一個比 nums[i] 大的數」
    - 交換它們
3. 將 i+1 之後的部分反轉
    - 讓右半部變最小


## 4. Pseudocode
```text
START

1. 從後面找第一個 i，使 nums[i] < nums[i+1]
   如果找不到 → reverse entire array → return

2. 從後面找第一個 j，使 nums[j] > nums[i]

3. swap(nums[i], nums[j])

4. reverse(nums[i+1 : end])

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else {
                // 避免重複加入
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }

        return ans;
    }
};
```
**Why it works:**

- 右側已經是「遞減排列」，代表已經是局部最大
- 找到第一個破壞遞減的位置（pivot）
- 在右側找剛好比它大的數交換 → 保證最小增量
- 最後反轉右半部 → 讓它變成最小排列
- 

### Reflection
- What challenges did you face?
    - 一開始容易誤以為要用排序或暴力 permutation
    - 交換後還要再反轉這一步很容易漏掉
- How would you improve this solution?
    - 
- What did you learn?
    - swap + reverse 是經典組合技巧