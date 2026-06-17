# LeetCode 670-Maximum Swap

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 670
- **Problem Title:** Maximum Swap
- **Problem Link:** https://leetcode.com/problems/maximum-swap/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)


## 2. Problem Statement in My Own Words
給定一個非負整數 num。

你最多只能交換其中兩個數字一次（也可以不交換），請找出交換後能得到的最大數值。

例如：
num = 2736

交換 2 和 7：
7236

這是能得到的最大值，因此回傳 7236。

### 輸入
    一個非負整數 num
###　輸出
    經過最多一次交換後所能得到的最大整數
### 主要限制與規則
- 最多只能交換一次。
- 可以選擇不交換。
- 必須回傳最大的可能結果。
### 核心任務
    找出兩個位置交換後能產生的最大數字。

## 3. Thinking Logic and Solution Strategy
### 最初想法
由於題目只允許交換一次，因此最直接的方法就是：
1. 將數字轉成字串。
2. 嘗試所有可能的交換組合。
3. 每交換一次就轉回整數。
4. 更新目前最大值。
因為 LeetCode 的測資範圍不大（最多 10 位數左右），暴力枚舉所有交換組合即可通過。
### 最終策略
使用雙層迴圈枚舉所有 (i, j)：

for (int i = 0; i < s.size(); i++)
    for (int j = i + 1; j < s.size(); j++)
1. 交換兩個位置。
2. 計算交換後的數字。
3. 更新最大值。
4. 換回來繼續測試下一組。


## 4. Pseudocode
```text
START

1. 將 num 轉成字串 s
2. ans = num

3. 對每個位置 i

      對每個位置 j > i

            交換 s[i], s[j]

            ans = max(ans, stoi(s))

            換回原本位置

4. 回傳 ans

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int ans = num;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                swap(s[i], s[j]);

                ans = max(ans, stoi(s));

                swap(s[i], s[j]);
            }
        }

        return ans;
    }
};
```
**Why it works:**
- 枚舉所有交換可能。
- 每組交換都會被檢查一次。
- 不會漏掉任何合法答案。
- 最後保留最大值即可。 

### Reflection
- What challenges did you face?
    - 一開始不容易判斷應該使用貪心法還是暴力搜尋。
- How would you improve this solution?
    - 目前做法會枚舉所有交換組合，時間複雜度較高。
    - 使用貪心法可將時間複雜度降到 O(n)，避免嘗試所有可能的交換組合。
- What did you learn?
    - 在位數較少的情況下，暴力法有時是最快且最容易驗證正確性的解法。
    - 使用貪心法之前，需要先證明為什麼該策略一定能得到最佳解。