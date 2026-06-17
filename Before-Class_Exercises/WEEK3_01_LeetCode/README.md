# LeetCode 231-Power of Two

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 231
- **Problem Title:** Power of Two
- **Problem Link:** https://leetcode.com/problems/power-of-two/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode01.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個整數 n
### 輸出
判斷 n 是否為 2 的冪次方，如果是回傳 true，否則回傳 false
### 規則
- 2 的冪：例如 1, 2, 4, 8, 16, ...
- 必須是正整數
- 不能有其他因子（除了 2）
### 核心任務
判斷一個數字能不能不斷除以 2，最後變成 1，中間都不能有餘數。

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- 一開始想到「只要是 2 的倍數就可以」
- 但很快發現像 6, 10, 12 也是 2 的倍數，但不是 2 的冪
- 所以不能只檢查一次

### Final Strategy
- 使用遞迴（或迴圈）不斷做：
    - 如果 n <= 0 → false
    - 如果 n == 1 → true
    - 如果 n 是奇數 → false
    - 否則繼續檢查 n / 2

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. 讀入 n
2. 如果 n <= 0 → 回傳 false
3. 如果 n == 1 → 回傳 true
4. 如果 n 是奇數 → 回傳 false
5. 回傳 isPowerOfTwo(n / 2)
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
// Paste the incorrect, incomplete, or rejected version here.
```

**Why it failed:**

- 
- 

### Correct Code

```cpp
class Solution {
    public:
     bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        return (n%2==0) && isPowerOfTwo(n/2);
    }
};
```

**Why it works:**

- 每次都確保可以整除 2
- 持續縮小問題規模
- 最終必須走到 1 才算成功



## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic |  |  |
| Edge Cases |  |  |
| Output Handling |  |  |
| Other |  |  |

### Reflection

- What mistake did you make?
- What did you learn from debugging this problem?
- If you solve a similar problem again, what will you do better?