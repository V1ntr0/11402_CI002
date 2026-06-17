# LeetCode 1109 - Corporate Flight Bookings

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1109
- **Problem Title:** Corporate Flight Bookings
- **Problem Link:** https://leetcode.com/problems/corporate-flight-bookings/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個二維整數陣列 `bookings`，其中每個元素 `bookings[i] = [first_i, last_i, seats_i]` 代表一個預訂紀錄（表示從航班 `first_i` 到 `last_i` 的每個航班都預訂了 `seats_i` 個座位）；以及一個整數 `n`，代表總共有幾個航班（航班編號為 `1` 到 `n`）。
    
### 輸出
一個長度為 `n` 的整數陣列，代表每個航班（從 1 到 n）最終被預訂的總座位數。
    
### 主要限制與規則
- 航班編號從 `1` 開始（1-based indexing）。
- 陣列長度與預訂紀錄的數量最大可達到 $2 \times 10^4$，若對每筆紀錄都用迴圈逐一在區間內加法，時間複雜度會達到 $O(\text{bookings.size()} \times n)$，這在極端測資下會導致逾時（TLE）。

### 核心任務
高效地對一個陣列的多個重疊區間進行批量加法操作，並在最後計算出每個位置的最終累積數值。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 最直覺的方法是走訪每一筆預訂紀錄 `[first, last, seats]`，然後用一個內層迴圈從 `first` 到 `last` 把對應航班的座位數加上 `seats`。
- 如前面所述，這種暴力法在區間很大、紀錄很多時非常低效，需要尋找一種能夠「只在區間端點做標記」，最後一次結算的優化技巧。


### 最終策略
1. 採用**差分陣列（Difference Array）**的核心思想。
2. 建立一個大小為 `n + 1` 的差分陣列 `diff`，並初始化為 0。為了配合程式習慣，將航班編號從 1-based 轉換為 0-based。
3. 對於每筆紀錄 `[first, last, seats]`，不直接填滿區間，而是進行端點標記：
   - 在區間起點 `first` 加上座位數：`diff[first] += seats`。
   - 在區間終點的下一個位置 `last + 1` 減去座位數：`diff[last + 1] -= seats`（若超出陣列邊界則不操作）。
4. 標記完成後，利用差分陣列與前綴和的數學關係，由前往後做**前綴和（Prefix Sum）的還原累加**。
5. 還原後的結果即為每個航班最終的預訂總座位數。


## 4. Pseudocode
```text
START
1. Initialize a difference array diff of size n + 1 with all zeros
2. FOR each booking b IN bookings:
       first = b[0] - 1
       last = b[1] - 1
       seats = b[2]
       diff[first] = diff[first] + seats
       IF last + 1 < n THEN
           diff[last + 1] = diff[last + 1] - seats
       END IF
3. Initialize an answer array ans of size n
4. ans[0] = diff[0]
5. FOR i from 1 to n - 1:
       ans[i] = ans[i - 1] + diff[i]
6. RETURN ans
END
```
## 5. Correct Code
### Correct Code

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        for (auto &b : bookings) {
            int first = b[0] - 1;  // convert to 0-based
            int last = b[1] - 1;
            int seats = b[2];

            diff[first] += seats;
            if (last + 1 < n) {
                diff[last + 1] -= seats;
            }
        }

        vector<int> ans(n);
        ans[0] = diff[0];

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + diff[i];
        }

        return ans;
    }
};

**Why it works:**
- **區間操作常數化：** 差分陣列的核心在於，對一個區間 `[L, R]` 整體加上 `V`，等同於在其差分陣列中令 `diff[L] += V` 且 `diff[R + 1] -= V`。這一步不需要走訪整個區間，時間複雜度僅為 $O(1)$。
- **單次掃描還原：** 最後利用前綴和由左往右累加時，`diff[L]` 帶來的增加效果會一直向後傳遞，直到遇到 `diff[R + 1]` 的減法將其抵消。這樣用一趟 $O(n)$ 的迴圈就能把所有區間的疊加結果完美還原出來。
- **極佳的時間效能：** 整體演算法分為兩部分：標記端點需要 $O(\text{bookings.size()})$，還原陣列需要 $O(n)$，總時間複雜度為線性 $O(\text{bookings.size()} + n)$，完美通過測試。

### Reflection
- What challenges did you face?
    - 題目給定的是 1-based 的航班編號，在轉換為 0-based 索引進行差分操作時，需要特別小心 `last + 1` 邊界是否會越界的問題，程式碼中透過 `last + 1 < n` 進行了安全的範圍防護。
- How would you improve this solution?
    - 若想進一步優化空間，可以直接將 `ans` 陣列本身當作差分陣列來做端點標記，最後在 `ans` 上原地進行前綴和累加，這樣可以把額外空間複雜度壓縮到純粹的 $O(1)$。
- What did you learn?
    - 深入理解了「差分陣列（Difference Array）」在處理**頻繁區間批量修改（Range Update）**問題時的強大威力。它能將高成本的區間走訪轉化為低成本的端點標記，再配合前綴和進行單次結算，是演算法中非常實用的優化技巧。