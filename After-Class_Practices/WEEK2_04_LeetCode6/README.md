# LeetCode 6-Zigzag Conversion

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 6
- **Problem Title:** Zigzag Conversion
- **Problem Link:** https://leetcode.com/problems/zigzag-conversion/description/
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/LeetCode.cpp)

## 2. Problem Statement in My Own Words

給定一個字串 s 和一個整數 numRows。
請將字串依照 Zigzag（Z 字型）方式排列，然後依照每一列由上到下的順序讀取，回傳新的字串。
例如：
PAYPALISHIRING
numRows = 3

排列後：
P   A   H   N
A P L S I I G
Y   I   R

依照列讀取：
PAHNAPLSIIGYIR

### 輸入
    字串 s
    列數 numRows
###　輸出
    Zigzag 轉換後的新字串
### 主要限制與規則
- 字元依序放入 Zigzag 中。
- 到達最上方或最下方時改變方向。
- 若 numRows = 1，結果與原字串相同。
### 核心任務
    模擬 Zigzag 的移動過程，最後將每一列的字元串接起來。

## 3. Thinking Logic and Solution Strategy
### 最初想法
一開始想到直接建立二維矩陣模擬整個 Zigzag 圖形。

例如：
P   A   H   N
A P L S I I G
Y   I   R
將每個字元放到正確位置後再逐列讀取。
但這種方法：
- 需要額外的二維空間。
- 位置計算較複雜。
- 實作容易出錯。


### 最終策略
    其實不需要真的建立整個 Zigzag 圖形。
只需要：
1. 建立 numRows 個字串。
2. 模擬字元在列之間上下移動。
3. 將字元加入目前所在列。
4. 最後把所有列串接起來即可。

利用：curRow 記錄目前在哪一列。
利用：dir , 控制方向：+1 往下,-1 往上

當到達：第 0 列或最後一列，時改變方向。

## 4. Pseudocode
```text
START

1. 如果 numRows == 1
      return s

2. 建立 rows[numRows]

3. curRow = 0
4. dir = -1

5. 對每個字元 c

      加入 rows[curRow]

      如果目前在最上面或最下面
           改變方向

      curRow += dir

6. 將所有 rows 串接

7. 回傳結果

END
```
## 5. Correct Code
### Correct Code

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);
        int curRow = 0;
        int dir = -1;

        for (char c : s) {
            rows[curRow] += c;

            if (curRow == 0 || curRow == numRows - 1) {
                dir *= -1;
            }

            curRow += dir;
        }

        string ans;
        for (string &row : rows) {
            ans += row;
        }

        return ans;
    }
};
```
**Why it works:**

- 使用 rows 儲存每一列字元。
- curRow 記錄目前所在列。
- dir 控制往上或往下移動。
- 到達頂端或底端時改變方向。
- 最後將所有列依序串接。
完整模擬了 Zigzag 的走法。
### Reflection
- What challenges did you face?
    - 一開始誤以為字元只要平均分配到各列即可，忽略了 Zigzag 最重要的「上下來回移動」特性。
- How would you improve this solution?
    - 
- What did you learn?
    - 這類模擬題最重要的是先理解資料移動規則，而不是急著設計資料結構。只要正確模擬移動過程，實作其實非常簡單。