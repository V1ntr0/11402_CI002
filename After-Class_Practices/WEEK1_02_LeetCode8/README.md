# LeetCode 8-String to Integer (atoi)

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 8
- **Problem Title:** String to Integer (atoi)
- **Problem Link:** https://leetcode.com/problems/string-to-integer-atoi/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

給定一個字串 s，模擬 C/C++ 中 atoi() 的行為，將字串轉換成整數。

### 輸入
    一個字串 s
###　輸出
    回傳轉換後的整數結果。
### 主要限制與規則
- 轉換過程必須遵守以下規則：
    1. 忽略開頭的空白字元。
    2. 接著可以出現一個正號 + 或負號 -。
    3. 讀取後續連續的數字字元。
    4. 一旦遇到非數字字元便停止讀取。
    5. 如果沒有讀到任何數字，回傳 0。
    6. 若結果超出 32-bit signed integer 範圍：
        - 小於 INT_MIN 回傳 INT_MIN
        - 大於 INT_MAX 回傳 INT_MAX
### 核心任務
    依照題目規定解析字串，並正確處理空白、正負號、非數字字元與 Overflow 問題。

## 3. Thinking Logic and Solution Strategy
### 最初想法
一開始想到直接使用 C++ 的函式，例如：stoi(s);
但題目要求模擬 atoi() 的行為，而且需要自行處理：
- 前導空白
- 正負號
- 非法字元
- Overflow

因此必須手動解析整個字串。

### 最終策略
- 按照題目規則一步一步掃描字串：
    1. 跳過所有前導空白。
    2. 判斷是否有正負號。
    3. 持續讀取數字字元。
    4. 每加入一位數字就檢查是否超出整數範圍。
    5. 最後乘上符號並回傳結果。

## 4. Pseudocode
```text
START

1. i = 0
2. sign = 1
3. num = 0

4. 跳過所有前導空白

5. 如果遇到 '+' 或 '-'
      紀錄符號
      i++

6. 當前字元是數字時：
      num = num * 10 + 當前數字

      如果超過 INT_MAX
           回傳 INT_MAX

      如果小於 INT_MIN
           回傳 INT_MIN

      i++

7. 回傳 num * sign

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        long long num = 0;
        int sign = 1;

        // 1. 跳過空白
        while (i < n && s[i] == ' ')
            i++;

        // 2. 處理正負號
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. 讀數字
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4. overflow 提前處理
            if (sign == 1 && num > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(num * sign);
    }
};
```
**Why it works:**

- 完整依照題目規則解析字串。
- 正確處理前導空白與正負號。
- 遇到非數字字元會立即停止讀取。
- 使用 long long 避免計算過程溢位。
- 超出範圍時立即回傳對應邊界值。
### Reflection
- What challenges did you face?
    - 
- How would you improve this solution?
    - 提前考慮 Overflow，而不是最後才檢查。
- What did you learn?
    - 遇到 Parsing 題目時，要先把規則拆解成明確步驟，再依序處理。這樣比較不容易漏掉特殊情況。