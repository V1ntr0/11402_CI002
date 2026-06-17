# LeetCode 1046 - Last Stone Weight

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1046
- **Problem Title:** Last Stone Weight
- **Problem Link:** https://leetcode.com/problems/last-stone-weight/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個整數陣列 `stones`，其中 `stones[i]` 代表第 `i` 顆石頭的重量。
    
### 輸出
一個整數，代表最後剩下那顆石頭的重量。如果所有石頭都被完全粉碎，則回傳 `0`。
    
### 主要限制與規則
遊戲規則如下：
1. 每一回合，從所有石頭中挑選出**重量最重**的兩顆石頭（假設重量分別為 `x` 和 `y`，且 `x <= y`）。
2. 將這兩顆石頭互相碰撞：
   - 若 `x == y`，兩顆石頭都會完全粉碎。
   - 若 `x != y`，重量為 `x` 的石頭完全粉碎，而重量為 `y` 的石頭重量會變成 `y - x`。
3. 重複上述步驟，直到最多只剩下一顆石頭為止。

### 核心任務
在每回合中，必須動態且高效地找出當前剩餘石頭中的「最大值」與「次大值」進行碰撞，並動態將碰撞後的剩餘重量放回群集。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 最直覺的方法是每次都將陣列重新進行排序（由大到小），接著取出前兩個元素進行相減，並將結果放回陣列，重複執行直到陣列長度小於等於 1。
- 然而，如果每回合都使用 `sort` 重新排序，時間複雜度會達到 $O(n^2 \log n)$，在频繁更新資料且需要即時取得最大值的情境下效率非常低。
- 我們需要一個資料結構，能夠在每次加入新石頭（插入）或獲取前兩大石頭（獲取極值）時，都能在對數時間 $O(\log n)$ 內完成。這正是**最大堆疊 / 優先佇列（Max-Heap / Priority Queue）**的標準應用場景。


### 最終策略
1. 使用 `std::priority_queue<int>` 建立一個**最大堆疊（Max-Heap）**，使內部的石頭重量永遠自動將最大值排在最頂端。
2. 遍歷輸入的 `stones` 陣列，將所有石頭依序推入（`push`）最大堆疊中。
3. 開啟一個 `while` 迴圈，條件為堆疊內部的石頭數量大於 1（`pq.size() > 1`）。
4. 在迴圈中，連續彈出兩個頂端元素：
   - 第一個彈出的是當前最重的石頭 `y = pq.top()`。
   - 第二個彈出的是當前次重的石頭 `x = pq.top()`。
5. 比較 `x` 與 `y`：
   - 若 `y != x`，則將相減後的剩餘重量 `y - x` 重新推入堆疊中。
   - 若 `y == x`，則不需要推入任何新元素（代表兩者皆粉碎）。
6. 當迴圈結束，堆疊內可能剩下 1 顆石頭或完全清空。利用三元運算子判斷：若為空則回傳 `0`，否則回傳 `pq.top()`。


## 4. Pseudocode
```text
START
1. Initialize max-heap pq
2. FOR each stone IN stones:
       pq.push(stone)
   END FOR
3. WHILE pq.size() > 1:
       y = pq.top()
       pq.pop()
       x = pq.top()
       pq.pop()
       IF y != x THEN
           pq.push(y - x)
       END IF
   END WHILE
4. RETURN pq.empty() ? 0 : pq.top()
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();

            int x = pq.top();
            pq.pop();


            if (y != x) {
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
```
**Why it works:**
- **動態排序（Max-Heap）：** 透過 C++ 預設的 `priority_queue`，在不需手動重新呼叫 `sort` 的前提下，確保每次 `pq.top()` 撈出來的組合必然是全域最重與次重的兩顆石頭。
- **對數時間內自我重構：** 每次取出極值與塞回差值時，堆疊在底層進行調整的時間複雜度皆為穩定的 $O(\log m)$（$m$ 為當前堆疊內石頭數），整體時間複雜度優化至 $O(n \log n)$，執行效率極高。
- **嚴謹的終止條件與空值防護：** 迴圈控制在 `pq.size() > 1`，能保證在嘗試連續彈出兩顆石頭時絕對不會發生空堆疊錯誤（Undefined behavior）。最後的 `pq.empty()` 判斷也完美兼容了所有石頭成對粉碎（例如 `[2, 2]`）的極端邊界狀況。

### Reflection
- What challenges did you face?
    - 本題的規則與資料移動特性非常明確，主要的思考突破點在於辨識出「每輪需要重複取得當前最大值」的核心特徵，進而選擇 Max-Heap 來取代傳統的暴力排序。
- How would you improve this solution?
    - 若想追求極致的效能，可以直接使用 `priority_queue<int> pq(stones.begin(), stones.end());`。這種基於範圍建構子（Range Constructor）的初始化方法，底層會使用內建的 `heapify` 演算法，能將建置最大堆疊的時間複雜度進一步降低至線性時間 $O(n)$。
- What did you learn?
    - 更加熟練了標準 Max-Heap 的應用場景。深刻體會到當一個題目涉及「需要頻繁動態更新資料、且每次操作都固定要求取得當前集合的極值（最大值或最小值）」時，優先佇列（Priority Queue）就是最高效的標配資料結構。