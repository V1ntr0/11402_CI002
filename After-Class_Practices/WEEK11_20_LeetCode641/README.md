# LeetCode 641 - Design Circular Deque

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 641
- **Problem Title:** Design Circular Deque
- **Problem Link:** https://leetcode.com/problems/design-circular-deque/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
- `MyCircularDeque(k)`：初始化一個大小為 `k` 的雙端循環佇列。
- `insertFront(value)`：往隊頭加一個數字。
- `insertLast(value)`：往隊尾加一個數字。
- `deleteFront()`：從隊頭刪一個數字。
- `deleteLast()`：從隊尾刪一個數字。
- `getFront()`：看最前面的數字。
- `getRear()`：看最後面的數字。
- `isEmpty()`：檢查是不是空的。
- `isFull()`：檢查是不是滿的。
    
### 輸出
- 新增和刪除的操作都回傳布林值，代表有沒有成功。
- `getFront` 和 `getRear` 回傳對應的數字，如果沒東西就回傳 `-1`。
- `isEmpty` 和 `isFull` 回傳布林值。
    
### 主要限制與規則
- 不能用內建的資料結構。
- 既然是雙端佇列（Deque），頭和尾都要支援新增跟刪除。
- 一樣要把陣列的頭尾接起來，重複利用格子。

### 核心任務
在固定大小的陣列中，同時管理「前端」與「後端」兩邊的指標，並且在指標往前遞減或往後遞增時，用餘數運算讓它們在陣列邊界安全地繞圈圈。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 延續上一題循環佇列（Circular Queue）的想法，用固定大小的陣列來做。
- 因為這題要在頭和尾兩邊做事情，指標移動會出現「往前減 1」的情況。
- 如果不希望空和滿的指標狀態撞在一起，最簡單乾淨的作法一樣是**把陣列空間多開一格（k + 1）**。


### 最終策略
1. 宣告陣列大小為 `k + 1`，並準備兩個指標 `front`（指向最前面有資料的位置）和 `rear`（指向最後面有資料的「下一格空位」）。
2. **判斷空和滿**：
   - 空的：`front == rear`。
   - 滿的：`(rear + 1) % capacity == front`。
3. **`insertFront`**：要在頭部加資料，`front` 指標必須**往左移（減 1）**。為了怕減完變負數，公式寫成 `front = (front - 1 + capacity) % capacity`，然後把值填進去。
4. **`insertLast`**：要在尾部加資料，直接把值填在目前的 `rear`，然後 `rear` **往右移（加 1）**：`rear = (rear + 1) % capacity`。
5. **`deleteFront`**：從頭部移資料，直接把 `front` **往右移（加 1）**：`front = (front + 1) % capacity`。
6. **`deleteLast`**：從尾部移資料，`rear` 必須**往左移（減 1）**：`rear = (rear - 1 + capacity) % capacity`。
7. **看資料**：
   - `getFront()`：直接拿 `q[front]`。
   - `getRear()`：拿 `q[(rear - 1 + capacity) % capacity]`。


## 4. Pseudocode
```text
START
1. Define class MyCircularDeque:
       capacity = k + 1
       Initialize array q of size capacity
       front = 0, rear = 0
       
       FUNCTION isEmpty():
           RETURN front == rear
           
       FUNCTION isFull():
           RETURN (rear + 1) % capacity == front
           
       FUNCTION insertFront(value):
           IF isFull() THEN RETURN false
           front = (front - 1 + capacity) % capacity
           q[front] = value
           RETURN true
           
       FUNCTION insertLast(value):
           IF isFull() THEN RETURN false
           q[rear] = value
           rear = (rear + 1) % capacity
           RETURN true
           
       FUNCTION deleteFront():
           IF isEmpty() THEN RETURN false
           front = (front + 1) % capacity
           RETURN true
           
       FUNCTION deleteLast():
           IF isEmpty() THEN RETURN false
           rear = (rear - 1 + capacity) % capacity
           RETURN true
           
       FUNCTION getFront():
           IF isEmpty() THEN RETURN -1
           RETURN q[front]
           
       FUNCTION getRear():
           IF isEmpty() THEN RETURN -1
           RETURN q[(rear - 1 + capacity) % capacity]
END
```
## 5. Correct Code
### Correct Code
```cpp
class MyCircularDeque {
private:
    vector<int> q;
    int front;
    int rear;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        q.resize(capacity);
        front = 0;
        rear = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        q[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        q[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return q[front];
    }
    
    int getRear() {
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
- **多留一格策略依然有效**：透過多開一個位置，我們不需要引入 `size` 或 `count` 變數，直接用 `front` 和 `rear` 的相對位置就能完美分清空跟滿。
- **加減法邊界都照顧到了**：往右移動用 `(idx + 1) % capacity`，往左移動用 `(idx - 1 + capacity) % capacity`。這兩個數學公式確保指標無論往前走還是往後退，都不會超出 `[0, capacity - 1]` 的陣列索引範圍。
- **效能全部都是常數**：因為只涉及到基本的陣列讀寫和簡單的加減乘除，所有操作的時間複雜度都維持在 $O(1)$。

### Reflection
- What challenges did you face?
    - 這題最容易亂掉的地方是 `insertFront` 的順序。因為 `front` 指向的是當前有資料的最前格，所以如果要「在前面塞新資料」，必須**先讓 `front` 往左退一格，再把值寫進去**。這跟 `insertLast` 剛好相反（先寫值，再把 `rear` 往右進一格）。只要把這兩個的對稱性想清楚，就不會寫錯。
- How would you improve this solution?
    - 
- What did you learn?
    - 更加熟悉了循環指針的控制方法。這次學會了除了往後繞圈，如何透過「加上總長度再做模運算」來達到安全的「逆向（往前）繞圈」，這在設計許多雙向循環的資料結構時非常好用。