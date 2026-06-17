# LeetCode 125-Valid Palindrome

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 125
- **Problem Title:** Valid Palindrome
- **Problem Link:** https://leetcode.com/problems/valid-palindrome/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)


## 2. Problem Statement in My Own Words

給定一個字串 s，判斷它是否為迴文。

### 輸入
    一個字串 s
###　輸出
    若為迴文則回傳 true
    否則回傳 false
### 主要限制與規則
- 非英數字元（Non-Alphanumeric）必須忽略。
- 大小寫視為相同。
- 空字串也算迴文。
### 核心任務
    過濾掉不需要比較的字元後，判斷字串正讀與反讀是否相同。

## 3. Thinking Logic and Solution Strategy
### 最初想法
一開始想到先建立一個新的字串：
1. 把所有字母轉成小寫。
2. 移除非英數字元。
3. 再檢查新字串是否為迴文。


### 最終策略
    使用雙指標（Two Pointers）直接在原字串上操作。
具體做法：
1. 左指標 l 從開頭開始。
2. 右指標 r 從尾端開始。
3. 如果遇到非英數字元就跳過。
4. 比較兩側字元（轉成小寫後）。
5. 若不同則直接回傳 false。
6. 若全部比對成功則回傳 true。

## 4. Pseudocode
```text
START

1. l = 0
2. r = 字串長度 - 1

3. 當 l < r 時

      左邊不是英數字
           l++

      右邊不是英數字
           r--

      如果 tolower(s[l]) != tolower(s[r])
           return false

      l++
      r--

4. return true

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {

            // 左邊跳過非字母數字
            while (l < r && !isalnum(s[l]))
                l++;

            // 右邊跳過非字母數字
            while (l < r && !isalnum(s[r]))
                r--;

            if (tolower(s[l]) != tolower(s[r]))
                return false;

            l++;
            r--;
        }

        return true;
    }
};
```
**Why it works:**

- 使用雙指標直接比較兩端字元。
- 利用 isalnum() 跳過所有無效字元。
- 利用 tolower() 忽略大小寫差異。
- 不需要建立額外字串。
- 時間複雜度與空間複雜度都較佳。
### Reflection
- What challenges did you face?
    - 
- How would you improve this solution?
    - 
- What did you learn?
    - 看到字串迴文題時，不一定要建立新的字串。很多情況下可以利用雙指標直接完成比較，減少額外空間使用。