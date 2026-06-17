# LeetCode 303-Range Sum Query - Immutable

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 303
- **Problem Title:** Range Sum Query - Immutable
- **Problem Link:** https://leetcode.com/problems/range-sum-query-immutable/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

## 2. Problem Statement in My Own Words
給定一個整數陣列 nums，需要多次查詢區間和。
每次查詢給你 left 和 right，請回傳：
nums[left] + nums[left+1] + ... + nums[right]

### 輸入
    一個整數陣列 nums
    多次查詢 (left, right)
###　輸出
    每次查詢的區間總和
### 主要限制與規則
- 陣列是 immutable（不能修改）
- 查詢次數很多
- 每次查詢要盡量快
### 核心任務
    快速計算區間和： Range Sum Query

## 3. Thinking Logic and Solution Strategy
### 最初想法

- 每次 query 都直接加總區間
- 時間複雜度 O(n) per query

### 最終策略

1. 預先計算 prefix sum
2. 每次 query 用 O(1) 計算


## 4. Pseudocode
```text
START

prefix[0] = 0

FOR i from 1 to n:
    prefix[i] = prefix[i-1] + nums[i-1]

QUERY left, right:
    return prefix[right+1] - prefix[left]

END
```
## 5. Correct Code
### Correct Code

```cpp
class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        prefix[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
```
**Why it works:**

- prefix[i] = 前 i 個元素總和
- 區間和可以轉換成差值：sum(left..right) = prefix[right+1] - prefix[left]
- 每次 query 都是 O(1)
- 前處理 O(n)

### Reflection
- What challenges did you face?
    - 不容易想到可以用「前綴和轉換區間問題」
- How would you improve this solution?
    - 熟練 prefix sum template
- What did you learn?
    - prefix sum 是處理區間問題的基本技巧