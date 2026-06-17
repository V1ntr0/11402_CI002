# LeetCode 169 - Majority Element

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 169
- **Problem Title:** Majority Element
- **Problem Link:** https://leetcode.com/problems/majority-element/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)


## 2. Problem Statement in My Own Words

### 輸入
一個整數陣列 `nums`

### 輸出
找出出現次數超過一半的元素（majority element）

### 規則
- 一定存在一個 majority element
- majority element 出現次數 > n / 2
- 陣列長度 n ≥ 1


### 核心任務
找出「出現次數超過一半」的那個數字

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- 一開始可能會想到用 hash map 計數
- 但需要額外 O(n) space
- 可以優化成 O(1) space


### Final Strategy

核心概念：

- 用 `count` 來「抵消不同元素」
- 同一個數 +1，不同數 -1
- count 變 0 時換候選人

## 4. Pseudocode

```text
START

majority = 0
count = 0

FOR each num in nums:
    IF count == 0:
        majority = num

    IF num == majority:
        count++
    ELSE:
        count--

RETURN majority

END
```
## 5. Fail Code vs Correct Code

### Correct Code
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                majority = num;
            }

            if (num == majority) {
                count++;
            } else {
                count--;
            }
        }

        return majority;
    }
};
```

**Why it works:**

- majority element 出現次數 > n/2
- 可以保證最後一定會留下它
- count 用來「抵消不同元素」
- 不需要額外空間

### Reflection
- What challenges did you face?
    - 比較難直觀理解的是「為什麼 count 抵消後，最後剩下的一定是 majority element」
- How would you improve this solution?
    - 
- What did you learn?
    - 學到 Boyer-Moore Voting Algorithm