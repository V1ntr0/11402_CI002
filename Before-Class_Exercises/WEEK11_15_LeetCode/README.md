# LeetCode 950 - Reveal Cards In Increasing Order

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 950
- **Problem Title:** Reveal Cards In Increasing Order
- **Problem Link:** https://leetcode.com/problems/reveal-cards-in-increasing-order/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個整數陣列 `deck`，代表一副牌中每張牌的點數。
    
### 輸出
一個整數陣列，代表重新排列後的發牌順序。
    
### 主要限制與規則
發牌（模擬）的規則如下：
1. 翻開牌組頂部的第一張牌，並將其從牌組中移除。
2. 如果牌組中還有牌，將此時頂部的第一張牌移到牌組的最底部。
3. 重複上述步驟，直到所有的牌都被翻開。
4. **目標：** 翻開的牌組順序必須是**嚴格遞增（由小到大）**的。

### 核心任務
將原本發牌的模擬過程「逆向操作」，從最終由小到大排好序的牌組出發，倒推出最初應該如何排列這副牌。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 順向模擬的話，可以用一個佇列（Queue）存索引來決定放牌位置。
- 但這題更適合**逆向思考（Reverse Simulation）**。既然發牌是「翻一張、移一張到底部」，那麼逆向回復就應該是「拿一張從底部移回頂部、再塞一張新牌到頂部」。
- 透過由大到小逆向處理排序好的牌，就能一步步還原出初始狀態。


### 最終策略
1. 先將 `deck` 陣列進行由小到大的排序。這樣我們就知道了最終翻開牌的正確順序。
2. 建立一個雙端佇列 `deque<int> dq` 用來模擬逆向組裝牌組的過程。
3. 從排序好的 `deck` 陣列**由後往前（由大到小）**進行走訪：
   - 如果此時 `dq` 不為空，代表要進行順向步驟 2 的逆操作：將目前 `dq` **最底部（back）的牌移回最頂部（front）**。
   - 接著，將當前這張較小的牌 `deck[i]` **推入頂部（push_front）**（對應順向步驟 1 剛被翻開移除的牌）。
4. 當所有牌都逆向塞回 `dq` 後，`dq` 內從頭到尾的順序就是最初正確的排牌順序。


## 4. Pseudocode
```text
START
1. Sort deck in ascending order
2. Initialize an empty deque dq
3. FOR i from deck.size() - 1 down to 0:
       IF dq is not empty THEN
           Move the element from the back of dq to the front of dq
       END IF
       Push deck[i] to the front of dq
4. Convert dq to a vector and RETURN it
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        deque<int> dq;

        for (int i = deck.size() - 1; i >= 0; i--) {
            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }

            dq.push_front(deck[i]);
        }

        return vector<int>(dq.begin(), dq.end());
    }
};
```
**Why it works:**
- **時空倒流的逆向還原：** 順向發牌是 `pop_front` 隨後將新的頂部移至 `push_back`；逆向還原時，我們反其道而行，先將 `back` 抽回 `push_front`，再把剛被翻開的牌 `push_front` 進去。整個過程就像把發牌動畫倒轉播放一樣。
- **由大到小的貪婪策略：** 排序後由大到小處理，確保了最後放進去的（也是最小的數字）一定會在最一開始被第一個翻開，完全符合題目要求 Increasing Order 的定義。
- **高效的 Deque 操作：** 使用 `std::deque` 可以在 $O(1)$ 的常數時間內完成前端與後端的插入與刪除，使得整體的逆向還原迴圈只需 $O(n)$，加上排序的 $O(n \log n)$，總時間複雜度為極佳的 $O(n \log n)$。

### Reflection
- What challenges did you face?
    - 順向思考這題會讓對位與索引的操作變得極其複雜。本題的突破點在於「逆向還原」，理清「把底部移回頂部」這個對稱操作是本題的核心關鍵。
- How would you improve this solution?
    - 目前的解法在時間複雜度 $O(n \log n)$ 與空間複雜度 $O(n)$ 上已經是最優的標準解，利用 `deque` 還原的程式碼結構也最為簡潔易讀。
- What did you learn?
    - 深刻體會到「逆向模擬（Reverse Engineering / Simulation）」在解題中的妙用。當一個製程或遊戲規則的順向推導很繁瑣，但最終狀態很明確時，嘗試將規則反過來「倒著推回去」，往往能讓複雜的問題迎刃而解。