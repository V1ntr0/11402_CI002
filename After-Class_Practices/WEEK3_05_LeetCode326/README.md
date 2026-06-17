# LeetCode 326-Power of Three

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 326
- **Problem Title:** Power of Three
- **Problem Link:** https://leetcode.com/problems/power-of-three/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

給定一個整數 n，判斷它是否為 3 的冪次方（Power of Three）。
所謂 3 的冪次方表示：
3⁰ = 1
3¹ = 3
3² = 9
3³ = 27
3⁴ = 81
...

如果存在某個整數 k ≥ 0，使得：
n = 3^k

則回傳 true，否則回傳 false。

### 輸入
    一個整數 n
###　輸出
    若 n 是 3 的冪次方，回傳 true
    否則回傳 false
### 主要限制與規則
- 負數不可能是 3 的冪次方。
- 0 也不是 3 的冪次方。
- 1 視為 3⁰，因此是合法答案。
### 核心任務
    判斷輸入數字是否可以一直被 3 整除，最後剛好變成 1。

## 3. Thinking Logic and Solution Strategy
### 最初想法
一開始想到直接使用迴圈產生：
1
3
9
27
81
...
直到超過 n 為止，再檢查是否相等。

雖然可行，但需要額外產生所有冪次方數字。

### 最終策略
利用 3 的冪次方特性：
如果：
n = 3^k
那麼它一定可以不斷被 3 整除：
例如：
27
→ 9
→ 3
→ 1
最後一定會得到 1。

若途中無法被 3 整除：
例如：
45
→ 15
→ 5
最後不會得到 1。
因此只要持續除以 3 即可判斷。

## 4. Pseudocode
```text
START

1. 如果 n <= 0
      return false

2. 當 n 可以被 3 整除

      n = n / 3

3. return (n == 1)

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;

        while (n % 3 == 0)
            n /= 3;

        return n == 1;
    }
};
```
**Why it works:**

- 先排除負數與 0。
- 只有能被 3 整除時才繼續除法。
- 所有 3 的冪次方最後都會變成 1。
- 非 3 的冪次方一定會停在其他數字。

### Reflection
- What challenges did you face?
    - 一開始只想到不停除以 3，卻忘記確認目前數字是否真的能被 3 整除。這會讓許多非 3 的冪次方數字被誤判。
- How would you improve this solution?
    - 
- What did you learn?
    - 