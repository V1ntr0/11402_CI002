# LeetCode 121-Best Time to Buy and Sell Stock

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 121
- **Problem Title:** Best Time to Buy and Sell Stock
- **Problem Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

## 2. Problem Statement in My Own Words
給定一個陣列 prices，其中 prices[i] 代表第 i 天的股票價格。

你只能進行一次交易：
- 買入一次
- 賣出一次
而且必須先買後賣。

請求出能獲得的最大利潤。如果無法獲利，則回傳 0。

### 輸入
    一個整數陣列 prices
###　輸出
    最大可能獲得的利潤
### 主要限制與規則
- 只能買入一次、賣出一次。
- 必須先買後賣。
- 賣出日期必須晚於買入日期。
- 如果沒有獲利機會，回傳 0。
### 核心任務
找出：
最大賣價 - 最小買價
且買入時間必須在賣出時間之前。

## 3. Thinking Logic and Solution Strategy
### 最初想法

一開始想到暴力法：
- 枚舉所有買入日。
- 再枚舉所有賣出日。
- 計算所有可能利潤。
- 找出最大值。
雖然能得到正確答案，但時間複雜度是 O(n²)。

當資料量變大時效率較差。

### 最終策略
使用一次遍歷（One Pass）。
核心概念：
1. 紀錄目前為止最低股價 minPrice
2. 每天都嘗試當成賣出日
3. 計算目前可獲得利潤
4. 更新最大利潤
具體流程：
1. 初始化最低價格為第一天價格
2. 逐天掃描價格
3. 更新最低價格
4. 計算當天賣出的利潤
5. 更新最大利潤

## 4. Pseudocode
```text
START

minPrice = prices[0]
maxProfit = 0

FOR 每個 price

    minPrice = min(minPrice, price)

    maxProfit = max(maxProfit,
                    price - minPrice)

RETURN maxProfit

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
```
**Why it works:**

- minPrice 永遠記錄目前為止最低的買入價格。
- 每一天都視為可能的賣出日。
- price - minPrice 代表當天賣出的利潤。
- 持續更新最大利潤。
- 一次遍歷即可找到最佳買賣時機。

### Reflection
- What challenges did you face?
    - 一開始容易想到暴力枚舉所有買賣組合。
- How would you improve this solution?
    - 
- What did you learn?
    - 遇到類似股票題時，可以優先考慮貪心（Greedy）或一次遍歷的方法。
    - 有些題目不需要列舉所有可能情況。