# LeetCode 622 - Design Circular Queue

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 622
- **Problem Title:** Design Circular Queue
- **Problem Link:** https://leetcode.com/problems/design-circular-queue/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
- `MyCircularQueue(k)`：初始化一個大小為 `k` 的循環佇列。
- `enQueue(value)`：往佇列尾巴塞入一個數字。
- `deQueue()`：從佇列頭部拿掉一個數字。
- `Front()`：看佇列最前面的數字。
- `Rear()`：看佇列最後面的數字。
- `isEmpty()`：檢查佇列是不是空的。
- `isFull()`：檢查佇列是不是滿的。
    
### 輸出
- `enQueue` 和 `deQueue` 回傳布林值，代表操作有沒有成功。
- `Front` 和 `Rear` 回傳對應的整數，如果佇列是空的就回傳 `-1`。
- `isEmpty` 和 `isFull` 回傳布林值。
    
### 主要限制與規則
- 不能直接拿程式語言內建的佇列（Queue）來用。
- 循環佇列的特點是把陣列的頭和尾接起來，這樣之前被刪掉釋放出來的格子可以重複利用。

### 核心任務
用固定大小的陣列來做一個佇列，並用餘數（模運算 `%`）來處理指標走到陣列盡頭後直接繞回最前面的情況。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 準備一個大小為 `k` 的陣列，還有兩個指標 `front`（起點）和 `rear`（終點）。
- 每次加資料 `rear` 就加 1，刪資料 `front` 就加 1。如果指標超過 `k`，就用 `% k` 讓它繞回來。
- 但這樣會遇到一個經典問題：當 `front == rear` 時，到底代表是「空的」還是「滿的」？這兩個狀態的指標重疊長得一模一樣。


### 最終策略
1. 為了解決空和滿分辨不出來的問題，最簡單的方法是**把陣列長度多開一格**，也就是宣告大小為 `k + 1` 的陣列。
2. 這樣一來，我們故意留一格不放資料：
   - **空的時候：** `front == rear`。
   - **滿的時候：** `(rear + 1) % capacity == front`（代表再加一個指標就會撞到頭了）。
3. **`enQueue`**：先檢查有沒有滿，沒滿就把資料放進 `rear` 的位置，然後 `rear = (rear + 1) % capacity`。
4. **`deQueue`**：先檢查有沒有空，沒空就把頭往前移：`front = (front + 1) % capacity`。
5. **取資料**：
   - `Front()` 直接拿 `front` 位置的資料。
   - `Rear()` 因為 `rear` 指向的是下一個要放資料的空位，所以最後一個有資料的位置是 `(rear - 1 + capacity) % capacity`。


## 4. Pseudocode
```text
START
1. Define class MyCircularQueue:
       capacity = k + 1
       Initialize array q of size capacity
       front = 0, rear = 0
       
       FUNCTION isEmpty():
           RETURN front == rear
           
       FUNCTION isFull():
           RETURN (rear + 1) % capacity == front
           
       FUNCTION enQueue(value):
           IF isFull() THEN RETURN false
           q[rear] = value
           rear = (rear + 1) % capacity
           RETURN true
           
       FUNCTION deQueue():
           IF isEmpty() THEN RETURN false
           front = (front + 1) % capacity
           RETURN true
           
       FUNCTION Front():
           IF isEmpty() THEN RETURN -1
           RETURN q[front]
           
       FUNCTION Rear():
           IF isEmpty() THEN RETURN -1
           RETURN q[(rear - 1 + capacity) % capacity]
END
```
## 5. Correct Code
### Correct Code
```cpp
class MyCircularQueue {
private:
    vector<int> q;
    int front;
    int rear;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k + 1;
        q.resize(capacity);
        front = 0;
        rear = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};
```
**Why it works:**
- **多留一格分清狀態：** 多開一格空間後，空和滿的條件就錯開了，完全不用另外用計數器紀錄數量。
- **指標自動回繞：** 用 `% capacity` 的加法，可以讓指標走到陣列最後一格時，加 1 直接變成 0，自然做到循環的效果。
- **倒退取值很安全：** 在 `Rear()` 拿最後一個數字時，因為要拿 `rear - 1`，為了怕 `rear` 是 0 減完變負數，先加上 `capacity` 再做 `%`，這樣在陣列邊界算索引時絕對不會出錯。
- **所有操作都是常數時間：** 每一個方法都只是單純的陣列指派跟數學運算，沒有任何迴圈，時間複雜度全部都是 $O(1)$。

### Reflection
- What challenges did you face?
    - 一開始如果不想要多開一格空間，就必須多用一個變數（例如 `size`）來記目前裡面有幾個數字。這題選擇多開一格的寫法，程式碼會更直覺，也少了一個變數需要維護。
- How would you improve this solution?
    - 如果真的完全不想浪費任何一格陣列空間，改用 `size` 計數器配合原本大小為 `k` 的陣列也是一個很常見的寫法。
- What did you learn?
    - 弄懂了循環佇列用陣列實作時的邊界處理，尤其是利用餘數運算來控制指標在固定空間裡不斷繞圈的技巧，這在底層記憶體管理很常用到。