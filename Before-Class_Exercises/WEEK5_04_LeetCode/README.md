# LeetCode 121 - Best Time to Buy and Sell Stock

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 121
- **Problem Title:** Best Time to Buy and Sell Stock
- **Problem Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
- **Source Code (Correct/Accepted):** [src/best-time-to-buy-and-sell-stock.cpp](./src/best-time-to-buy-and-sell-stock.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個整數陣列 prices，其中 prices[i] 代表第 i 天某支股票的價格。
    
### 輸出
一個整數，代表在這段期間內進行「一次買入和一次賣出」所能獲得的最大利潤。如果完全無法獲利，則回傳 0。
    
### 主要限制與規則
- 必須先買入才能賣出（不能在第 2 天買入但在第 1 天賣出）。
- 只能選擇某一天買入，並在未來的另一天賣出，最多只能進行一次交易。
- 陣列長度最高可能達到 10^5，因此不適合使用 O(n^2) 的暴力解法。

### 核心任務
在時間序列的陣列中，找到一個「未來的價格」減去「過去的價格」之最大差值（最大利潤）。    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 最直覺的想法是使用雙重迴圈（暴力法），列舉出所有可能的買入與賣出天數組合，計算利潤並找出最大值。
- 但這樣一來時間複雜度會達到 O(n^2)，在資料量高達 10^5 的測試資料下必定會導致 Time Limit Exceeded (TLE)。
- 必須找到只需遍歷陣列一次（O(n)）即可找出最大利潤的優化策略。


### 最終策略
1. 宣告兩個變數：min_price 紀錄到目前為止所遇到的最低股票價格（初始化為很大的數，如 INT_MAX）；max_profit 紀錄到目前為止所能獲得的最大利潤（初始化為 0）。
2. 走訪整個 prices 陣列。
3. 對於每一天的價格，首先更新 min_price（如果今天的價格比歷史最低還低，就更新它）。
4. 如果今天的價格大於 min_price，計算今天賣出可得的利潤（price - min_price），並嘗試更新 max_profit。
5. 遍歷結束後，max_profit 即為最終答案。


## 4. Pseudocode
START
1. Initialize min_price = INT_MAX
2. Initialize max_profit = 0
3. FOR each price IN prices:
       IF price < min_price THEN
           min_price = price
       ELSE IF price - min_price > max_profit THEN
           max_profit = price - min_price
       END IF
4. RETURN max_profit
END

## 5. Correct Code
### Correct Code

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int price : prices) {
            if (price < min_price) {
                min_price = price;
            } else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }

        return max_profit;
    }
};

**Why it works:**

- 單次遍歷的高效性：只需要一趟 O(n) 迴圈，同時維護「歷史最低價」與「最大獲利」，避免了暴力法重複計算的巢狀迴圈。
- 動態規劃與貪婪思維：對於每一天來說，最理想的買入時機一定是過去歷史中的最低點。程式在每一步都自動假設在 min_price 買入，並當下計算利潤，保證涵蓋了所有潛在的最佳交易時機。
- 空間代價極低：僅使用兩個常數變數來儲存狀態，空間複雜度為完美的 O(1)。
- 防錯處理：如果股票價格一路上跌，price < min_price 會不斷成立，而 else if 永遠不會觸發，最終會安全地回傳初始值 0。

### Reflection
- What challenges did you face?
    - 一開始不清楚如何同時找出買入點與賣出點，試圖去找出全域最低點，但全域最低點可能出現在最末端而無法在它之後賣出。
- How would you improve this solution?
    - 當前的方案已經在時間 O(n) 和空間 O(1) 上達到最優，程式碼也極為精簡，無更進一步的空間。
- What did you learn?
    - 學到了在處理時間序列的差值最大化問題時，透過維護一個「滾動的歷史極值（最低點）」，就可以在單次走訪中同步求解最佳解，這是一種很經典的動態規劃/貪婪技巧。