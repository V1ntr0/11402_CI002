# LeetCode 150 - Evaluate Reverse Polish Notation

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 150
- **Problem Title:** Evaluate Reverse Polish Notation
- **Problem Link:** https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個字串陣列 `tokens`，裡面算式是用後序表示寫成的，包含數字和四則運算符號（`+`, `-`, `*`, `/`）。
    
### 輸出
一個整數，代表這個算式計算出來的最終結果。
    
### 主要限制與規則
- 有效的運算符號只有 `+`、`-`、`*`、`/`。
- 兩個整數相除（`/`）只保留整數部分，也就是向零截斷（像 6 / -132 會變成 0）。
- 題目保證算式一定合法，不會出現除以 0 的情況，答案跟中間計算過程也不會超過 32 位元整數範圍。

### 核心任務
按照後序表示法的規則，遇到運算符號就拿出前面最近的兩個數字做計算，並算出整串算式的答案。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 這種後序表示法的特色是運算符號在數字後面，像是 `["2", "1", "+"]` 其實就是 `2 + 1`。
- 算式是由左往右讀取，每次看到符號就要找剛才最後看到的兩個數字來算。這種「後面讀到的先拿來用」的特性，直接用堆疊（Stack）來存數字是最自然的。


### 最終策略
1. 準備一個用來存整數的堆疊 `st`。
2. 從左到右一項一項檢查 `tokens` 裡的字串。
3. 如果讀到的是數字，就把字串轉成整數（可以用 `stoi` 函式），然後丟進堆疊裡。
4. 如果讀到的是運算符號（`+`, `-`, `*`, `/`）：
   - 從堆疊頂端拿出第一個數字（這是右操作數 `num2`）。
   - 再從堆疊頂端拿出第二個數字（這是左操作數 `num1`）。
   - 根據符號做對應的加減乘除，把算完的新數字再丟回堆疊裡。
5. 當所有字串都讀完後，堆疊裡最後留下來的那一個數字就是答案。


## 4. Pseudocode
```text
START
1. Initialize an empty integer stack st
2. FOR each token t IN tokens:
       IF t is "+", "-", "*", or "/" THEN
           num2 = st.pop()
           num1 = st.pop()
           IF t == "+" THEN result = num1 + num2
           ELSE IF t == "-" THEN result = num1 - num2
           ELSE IF t == "*" THEN result = num1 * num2
           ELSE IF t == "/" THEN result = num1 / num2
           st.push(result)
       ELSE
           st.push(convert_to_integer(t))
       END IF
   END FOR
3. RETURN st.pop()
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();

                if (t == "+") st.push(num1 + num2);
                else if (t == "-") st.push(num1 - num2);
                else if (t == "*") st.push(num1 * num2);
                else if (t == "/") st.push(num1 / num2);
            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};
```
**Why it works:**
- **順序沒有錯亂：** 堆疊後進先出的特性，剛好可以把前面的數字存起來。遇到符號時，先拿出來的會是右邊的數字，後拿出來的是左邊的數字，順序完全正確。
- **減法和除法不會反過來：** 透過先扣除 `num2` 再扣除 `num1`，在做 `num1 - num2` 或 `num1 / num2` 時，可以確保像是 `["4", "13", "/"]` 會正確算成 `4 / 13 = 0`，而不是 `13 / 4`。
- **字串轉換很方便：** 內建的 `stoi` 可以直接把字串（包含負數如 `"-11"`）安全地轉成整數存進堆疊。
- **時間與空間都很快：** 只要掃描一遍陣列，時間複雜度是 $O(n)$。堆疊最多存一半的數字，空間複雜度也是 $O(n)$。

### Reflection
- What challenges did you face?
    - 最容易弄錯的地方是拿數字的順序。因為先彈出來的數字其實在算式裡是排在後面的那一個（右邊），如果直接用 `num1 / num2` 但變數給錯，減法和除法就會算出反過來的錯誤答案。
- How would you improve this solution?
    - 如果想省一點點記憶體，可以不用標準的 `std::stack`，直接用原來的陣列 `tokens` 當作內容物來改，或者自己用一個指標模擬堆疊，不過這題直接用內建的就很夠快了。
- What did you learn?
    - 掌握了後序表示法的基本邏輯，也更清楚知道堆疊在處理這種有先後順序、需要暫存數字的數學算式時該怎麼應用。