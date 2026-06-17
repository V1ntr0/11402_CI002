# LeetCode 9-Palindrome Number

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 9
- **Problem Title:** Palindrome Number
- **Problem Link:** https://leetcode.com/problems/palindrome-number/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

給定一個整數 x，判斷它是否為Palindrome。
也就是從左往右讀與從右往左讀結果相同。

### 輸入
    一個整數 x
###　輸出
    如果是迴文數，回傳 true
    否則回傳 false
### 主要限制與規則
    負數不可能是迴文數，因為會有負號存在。
    需要正確處理各種整數情況。
    反轉數字時需注意可能發生溢位（Overflow）。
### 核心任務
    將數字反轉後，判斷是否與原本的數字相同。

## 3. Thinking Logic and Solution Strategy
### 最初想法
    最直覺的方法是把整數轉成字串，然後從頭尾開始比較字元是否相同。
    不過這題其實可以直接利用數學運算完成，不需要額外轉成字串。

### 最終策略
    利用取餘數與除法，把數字逐位反轉。

## 4. Pseudocode
```text
START
1. 如果數字小於 0，直接回傳 false。
2. 用變數 n 儲存原始數字。
3. 建立 rev 紀錄反轉後的結果。
4. 每次取出個位數加入 rev。
5. 最後比較 rev 是否等於原本的 x。
END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long n = x;
        long long rev = 0;

        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }

        return rev == x;
    }
};
```
**Why it works:**

- 先排除負數情況。
- 使用 long long 避免反轉過程溢位。
- 利用數學運算正確反轉每一位數字。
- 最後比較原數與反轉後數字即可得到答案。
### Reflection
- What challenges did you face?
    - 
- How would you improve this solution?
    - 即使題目邏輯很簡單，也必須注意邊界條件與資料型態的選擇。很多錯誤並非演算法本身，而是特殊情況沒有處理好。
- What did you learn?
    - 