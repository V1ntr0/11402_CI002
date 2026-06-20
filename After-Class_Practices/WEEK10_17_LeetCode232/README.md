# LeetCode 232 - Implement Queue using Stacks

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 232
- **Problem Title:** Implement Queue using Stacks
- **Problem Link:** https://leetcode.com/problems/implement-queue-using-stacks/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
- `MyQueue()`：初始化佇列物件。
- `push(int x)`：將元素 `x` 推入佇列尾端。
- `pop()`：移除並回傳佇列前端的元素。
- `peek()`：返回佇列前端的元素。
- `empty()`：回傳佇列是否為空。
    
### 輸出
- `pop()` 與 `peek()` 會回傳對應的整數值。
- `empty()` 會回傳一個布林值（`true` 或 `false`）。
    
### 主要限制與規則
- **必須只能使用標準的堆疊（Stack）操作**：即只能使用 `push to top`、`peek/pop from top`、`size` 與 `is empty`。
- 你所使用的程式語言如果不內建堆疊，可以用 `list` 或 `deque` 模擬，但必須確保只能呼叫標準的堆疊操作。
- 所有操作皆假設是有效的（例如：不會對空佇列呼叫 `pop` 或 `peek`）。

### 核心任務
利用兩個具有「後進先出（LIFO）」特性的堆疊，去模擬出一個具有「先進先出（FIFO）」特性的佇列。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 堆疊是後進先出（LIFO），而佇列是先進先出（FIFO）。如果要把順序倒過來，將一個堆疊的元素逐一彈出並推入另一個堆疊，它的順序就會剛好完美反轉。
- 可以在每次呼叫 `push` 時，就把所有舊資料搬到另一個堆疊，放入新資料後再搬回來。但這樣做每次 `push` 的時間複雜度會是 $O(n)$。


### 最終策略
1. 準備兩個堆疊：`stIn`（負責處理輸入 `push`）與 `stOut`（負責處理輸出 `pop` 與 `peek`）。
2. **`push(x)`**：非常簡單，直接將 `x` 推入 `stIn` 即可。時間複雜度為 $O(1)$。
3. **`pop()` 與 `peek()`**：這兩個操作都需要取得最先進入的元素。此時我們檢查 `stOut` 是否為空：
   - 如果 `stOut` 是空的，我們就把目前 `stIn` 裡面的**所有元素**逐一彈出並推入 `stOut`。經過這層轉移，`stIn` 底部最舊的元素，就會跑到 `stOut` 的頂端。
   - 如果 `stOut` 本身就還有元素，則直接對 `stOut` 進行 `pop()` 或 `top()`。
4. **攤銷分析（Amortized Analysis）**：雖然某一次搬移需要 $O(n)$ 的時間，但每個元素最多只會被放進 `stIn` 一次、搬到 `stOut` 一次、從 `stOut` 彈出一次。平均下來，每個操作的均攤時間複雜度是優雅的 $O(1)$。


## 4. Pseudocode
```text
START
1. Define class MyQueue:
       Initialize stacks stIn and stOut
       
       FUNCTION push(x):
           stIn.push(x)
           
       FUNCTION pop():
           IF stOut.empty() THEN
               WHILE stIn is not empty:
                   stOut.push(stIn.pop())
               END WHILE
           END IF
           RETURN stOut.pop()
           
       FUNCTION peek():
           IF stOut.empty() THEN
               WHILE stIn is not empty:
                   stOut.push(stIn.pop())
               END WHILE
           END IF
           RETURN stOut.top()
           
       FUNCTION empty():
           RETURN stIn.empty() AND stOut.empty()
END
```
## 5. Correct Code
### Correct Code
```cpp
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {}
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int val = stOut.top();
        stOut.pop();
        return val;
    }
    
    int peek() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};
```
**Why it works:**
- **雙堆疊分工明確：** 一個專職寫入（`stIn`），一個專職讀取（`stOut`），成功將不連續的資料轉換成局部有序的狀態。
- **自然的逆序還原：** `stIn` 彈出並壓入 `stOut` 的過程，在數學與邏輯上剛好完成了雙重否定等於肯定（LIFO $\times$ LIFO = FIFO），完美重現了佇列的先進先出特性。
- **卓越的均攤時間效能：** 只有當 `stOut` 被掏空、且又有讀取請求時才會觸發一次性的整體搬運。這確保了大部分常規操作都是常數時間 $O(1)$，符合工業級的高效能實作要求。
- **雙重空值判定：** `empty()` 方法同時檢驗了兩個堆疊，防止了當資料已經全數移至 `stOut` 時，因 `stIn` 為空而造成提早誤判的錯誤。

### Reflection
- What challenges did you face?
    - 在實作 `pop()` 和 `peek()` 時，必須注意程式碼的複用性。因為這兩個操作都要進行「若 `stOut` 為空，則倒扣 `stIn`」的檢查，將此邏輯抽離成獨立判斷或直接在兩者內部分別安全實作，可以防範操作時的邊界遺漏。
- How would you improve this solution?
    - 在實作細節上，可以讓 `pop()` 直接呼叫 `peek()` 來獲取頂端值，再進行彈出，這樣能進一步精簡程式碼。
- What did you learn?
    - 深入理解了「Amortized Complexity」的概念。學會了如何透過調整搬移的觸發時機（Lazy Evaluation），將原本代價高昂的操作拆分分攤到各個常數操作中，從而優化整體的架構效能。