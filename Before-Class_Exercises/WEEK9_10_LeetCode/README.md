# LeetCode 724 - Find Pivot Index

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 724
- **Problem Title:** Find Pivot Index
- **Problem Link:** https://leetcode.com/problems/find-pivot-index/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個整數陣列 `nums`。
    
### 輸出
一個整數，代表該陣列的「中心索引（Pivot Index）」。若不存在中心索引，則回傳 `-1`。
    
### 主要限制與規則
- 中心索引的定義：該索引「左側所有元素的相加總和」等於「右側所有元素的相加總和」。
- 如果中心索引在陣列的最左端（`i == 0`），其左側總和視為 `0`；同理，若在最右端，其右側總和亦視為 `0`。
- 若陣列中存在多個符合條件的中心索引，必須回傳**最左邊（最小）**的那個索引。

### 核心任務
在單次或低複雜度遍歷中，動態比對每個位置左右兩側的元素總和，找出最靠左的平衡點。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 最直覺的做法是對每一個索引 `i`，都用一個迴圈去計算它左邊 `0` 到 `i-1` 的總和，再用另一個迴圈去計算右邊 `i+1` 到末端的總和。
- 這種暴力法需要巢狀迴圈，時間複雜度會達到 $O(n^2)$。若能預先算出整個陣列的總和，就可以透過簡單的數學減法當場推導出右側的總和。


### 最終策略
1. 先遍歷一遍陣列，計算出所有元素的總和，儲存在變數 `totalSum` 中。
2. 宣告一個變數 `leftSum = 0`，用來動態紀錄目前走訪位置左側的所有元素總和。
3. 開始第二輪遍歷，當前指針為 `i`。
4. 利用公式動態推導出右側總和：`rightSum = totalSum - leftSum - nums[i]`（總和減去左邊、再減去當前元素，剩下的就是右邊）。
5. 比較 `leftSum` 是否等於 `rightSum`：
   - 若相等，因為是由左往右走訪，此時的 `i` 必定是最靠左的中心索引，立即回傳 `i`。
   - 若不相等，則將當前的 `nums[i]` 累加到 `leftSum` 中，繼續前進檢視下一個位置。
6. 若走訪結束仍未觸發相等條件，代表不存在中心索引，回傳 `-1`。


## 4. Pseudocode
```txet
START
1. Initialize totalSum = 0
2. FOR each num IN nums:
       totalSum = totalSum + num
3. Initialize leftSum = 0
4. FOR i from 0 to nums.size() - 1:
       rightSum = totalSum - leftSum - nums[i]
       IF leftSum == rightSum THEN
           RETURN i
       END IF
       leftSum = leftSum + nums[i]
5. RETURN -1
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
```
**Why it works:**
- **空間與時間的完美平衡：** 透過先求全域總和 `totalSum`，成功將右側區段和的計算轉化為 $O(1)$ 的常數數學運算，讓演算法整體時間複雜度優化至 $O(n)$。
- **天然的「最左優先」機制：** 由於 `for` 迴圈是嚴格從索引 `0` 開始往右遞增，一遇到滿足 `leftSum == rightSum` 的點就立刻 `return`，完美契合了題目要求「若有多個中心索引，回傳最左側者」的規則。
- **邊界條件自然相容：** 當 `i == 0` 時，`leftSum` 剛好為初始值 `0`，而 `rightSum` 為 `totalSum - 0 - nums[0]`，這與題目所定義「最左端點之左側總和為 0」完全一致，無須撰寫額外的 `if` 特判。

### Reflection
- What challenges did you face?
    - 在更新 `leftSum` 的時機上需要注意細節。必須在**比對完當前位置的平衡狀況後**，才可以把 `nums[i]` 加進 `leftSum`，否則在檢視 `i` 時，`leftSum` 就會錯誤地包含了 `nums[i]` 本身。
- How would you improve this solution?
    - 
- What did you learn?
    - 學到了利用 Total Sum 與 Rolling Prefix Sum 相互加減的技巧。不需開闢額外的陣列空間，即可在動態走訪的過程中同步取得任意切分點的左右兩側區間和。