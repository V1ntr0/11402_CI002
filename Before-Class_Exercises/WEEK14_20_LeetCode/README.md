# LeetCode 1845 - Seat Reservation Manager

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1845
- **Problem Title:** Seat Reservation Manager
- **Problem Link:** https://leetcode.com/problems/seat-reservation-manager/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
- `SeatManager(int n)`：初始化物件，總共有 `n` 個座位，編號從 `1` 到 `n`。
- `reserve()`：不帶參數，每次呼叫此方法表示要預訂一個座位。
- `unreserve(int seatNumber)`：帶入一個座位編號，表示要取消該座位的預訂。
    
### 輸出
- `reserve()`：回傳一個整數，代表被成功預訂的座位編號。
- 其餘方法不需回傳任何值。
    
### 主要限制與規則
- 每次呼叫 `reserve()` 時，系統必須**優先分配當前所有「未被預訂」的座位中，編號最小的那個座位**。
- 題目保證每次呼叫 `unreserve` 時，傳入的 `seatNumber` 在當下必定是處於「已被預訂」的狀態。
- 總共有多達 $10^5$ 次的線上操作，因此每次預訂與取消預訂的效率必須極高。

### 核心任務
設計一個資料結構來動態管理可用的座位，並在每次請求時，以低於 $O(n)$ 的時間複雜度快速找出並彈出最小值。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 可以建立一個大小為 `n + 1` 的布林陣列（或雜湊表）來記錄每個座位的預訂狀態。
- 當呼叫 `reserve()` 時，由前往後掃描陣列，遇到第一個未被預訂的座位就將其標記並回傳。
- 然而，這種做法在最差情況下的時間複雜度為 $O(n)$。在頻繁進行多達 $10^5$ 次操作的情境下，必定會遭遇逾時（TLE）。
- 需要一種資料結構，能在每次插入（取消預訂）或獲取最小值（預訂）時，都能在對數時間 $O(\log n)$ 內完成。這正是**最小堆疊 / 優先佇列（Min-Heap / Priority Queue）**的完美應用場景。


### 最終策略
1. 使用 `std::priority_queue` 建立一個**最小堆疊（Min-Heap）**，讓內部元素永遠自動將最小的值排在最頂端。
2. **初始化（Constructor）：** 使用一個迴圈，將編號 `1` 到 `n` 的所有座位依序推入（`push`）最小堆疊中，代表一開始所有座位皆為空閒可用。
3. **預訂座位（reserve）：** 直接透過 `pq.top()` 取出目前最頂端（即編號最小）的座位，隨後將其從堆疊中彈出（`pop`），並將此編號回傳。
4. **取消預訂（unreserve）：** 將釋放出來的 `seatNumber` 重新推入（`push`）最小堆疊中，使其重新進入可被分配的候選清單內。


## 4. Pseudocode
```text
START
1. Define class SeatManager:
       Initialize min-heap pq
       
       CONSTRUCTOR SeatManager(n):
           FOR i from 1 to n:
               pq.push(i)
           END FOR
           
       FUNCTION reserve():
           seat = pq.top()
           pq.pop()
           RETURN seat
           
       FUNCTION unreserve(seatNumber):
           pq.push(seatNumber)
END
```
## 5. Correct Code
### Correct Code
```cpp
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;

    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            pq.push(i);
        }
    }
    
    int reserve() {
        int seat = pq.top();
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
```
**Why it works:**
- **標準最小堆疊的特徵映射：** 透過指定 `greater<int>` 模板參數，C++ 的 `priority_queue` 會在底層自動維護成一棵二元最小堆疊。這保證了 `pq.top()` 永遠能在 $O(1)$ 的時間拿到最小編號的座位。
- **對數級別的動態調整：** 每次呼叫 `reserve()` 進行彈出，或者呼叫 `unreserve()` 重新置入時，最小堆疊的動態重構時間複雜度皆為穩定的 $O(\log m)$（$m$ 為當前可用座位數），完全能滿足大數據下的線上實時操作。
- **安全隔離狀態：** 由於題目保證取消預訂的座位必為已被預訂者，因此不會出現重複推入相同編號的問題，最小堆疊內部的資料一致性可以得到完美保障。

### Reflection
- What challenges did you face?
    - 本題難點在於如何選擇合適的資料結構。若習慣性使用陣列或佇列，會卡在尋找最左側可用點的演算法複雜度。一旦聯想到「動態維護極值」的特性並切換到 Heap 思考，題目就會變得非常直覺。
- How would you improve this solution?
    - 可以優化為「只用一個計數器記錄目前分配過的最大座位號，並只用 `pq` 儲存被取消預訂（unreserve）釋放出來的二手座位」。
        - 若 `pq` 為空，則直接遞增計數器分配新座位；
        - 若不為空，再從 `pq` 中撈取二手座位。如此一來，初始化只需 $O(1)$。
- What did you learn?
    - 複習了 C++ 最小堆疊（`greater<int>` 規格）的標準宣告與基礎操作。進一步理解了在多物件、多操作的「系統/管理員（Manager）」類別設計題中，利用優先佇列來處理動態排序。