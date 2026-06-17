# LeetCode 20 - Valid Parentheses

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 20
- **Problem Title:** Valid Parentheses
- **Problem Link:** https://leetcode.com/problems/valid-parentheses/description/
- **Source Code (Correct/Accepted):** [src/LeetCode.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

### 輸入
一個只包含字元 `'('`, `')'`, `'{'`, `'}'`, `'['` 和 `']'` 的字串 `s`。
    
### 輸出
一個布林值（`true` 或 `false`），代表該輸入字串中的括號組合是否合法。
    
### 主要限制與規則
- 左括號必須以相同類型的右括號閉合（例如 `(` 必須配對 `)`）。
- 左括號必須以正確的順序閉合（例如 `([)]` 是不合法的，因為內部未先閉合就先遇到了外部的右括號）。
- 每個右括號都必須有一個對應的相同類型左括號。

### 核心任務
利用「後進先出」的特性，確保每個最新出現的右括號，都能與當前最期待被閉合的左括號完美配對。
    

## 3. Thinking Logic and Solution Strategy
### 最初想法
- 括號配對具有對稱性與巢狀結構，最後被打開的左括號必須最先被閉合。
- 這具有典型的「後進先出（Last In, First Out）」特性，因此非常適合使用**堆疊（Stack）**資料結構來處理。
- 只要遇到左括號就存起來，遇到右括號就拿最後存進去的左括號出來比對。


### 最終策略
1. 宣告一個字元堆疊 `st`。
2. 走訪字串 `s` 中的每一個字元 `c`。
3. 如果 `c` 是左括號（`(`、`[`、`{`），將它推入（`push`）堆疊中。
4. 如果 `c` 是右括號（`)`、`]`、`}`），進行以下檢查：
   - 如果此時堆疊已空（`st.empty()`），說明有右括號卻沒有左括號可配對，直接回傳 `false`。
   - 檢查堆疊頂端（`st.top()`）的左括號是否與當前的右括號 `c` 同類型。若不匹配，代表順序錯誤，直接回傳 `false`。
   - 若匹配成功，將堆疊頂端的左括號彈出（`pop`）。
5. 遍歷結束後，檢查堆疊是否為空。若為空代表所有左括號都找到了歸宿，回傳 `true`；若不為空代表有孤立的左括號未被閉合，回傳 `false`。


## 4. Pseudocode
```text
START
1. Initialize an empty character stack st
2. FOR each character c IN string s:
       IF c == '(' OR c == '[' OR c == '{' THEN
           st.push(c)
       ELSE
           IF st.empty() THEN
               RETURN false
           END IF
           IF (c == ')' AND st.top() != '(') OR
              (c == ']' AND st.top() != '[') OR
              (c == '}' AND st.top() != '{') THEN
               RETURN false
           END IF
           st.pop()
       END IF
3. RETURN st.empty()
END
```
## 5. Correct Code
### Correct Code
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                if ((c == ')' && st.top() != '(') ||
                    (c == ']' && st.top() != '[') ||
                    (c == '}' && st.top() != '{')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
```
**Why it works:**
- **完美契合 LIFO 特性：** 堆疊（Stack）能自動幫我們維護最近一次未閉合的左括號。當遇到右括號時，`st.top()` 正好就是當前唯一合法的配對對象。
- **嚴謹的空堆疊檢查：** 程式碼在檢查 `st.top()` 之前先判斷了 `st.empty()`，有效防止了當字串開頭就是右括號（例如 `")("`）時，因存取空堆疊而導致的程式崩潰（Runtime Error）。
- **最終完整性驗證：** 結尾的 `return st.empty()` 可以漂亮地過濾掉左括號過多的場景（例如 `"(()"`），確保數量也完全對等。

### Reflection
- What challenges did you face?
    - 本題邏輯清晰，主要的細節在於要同時考慮「配對錯誤」、「右括號落單（堆疊提早空）」與「左括號落單（結尾堆疊不為空）」這三種失敗情境。
- How would you improve this solution?
    - 在程式碼的可讀性上，可以在遇到左括號時改為將「對應的右括號」推入堆疊，這樣後續比對時只需判斷 `c == st.top()` 即可，能讓條件式更精簡。
- What did you learn?
    - 深入掌握了堆疊（Stack）在處理具有「對稱性」、「巢狀消除」或「最近相關性」問題時的經典應用。