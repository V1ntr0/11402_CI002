
# UVa 100 - The 3n+1 Problem

## Problem Description
根據題目的3n+1 序列演算法，找出給定的兩個數字區間中的cycle length，並輸出該區間內的最大 cycle length。
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36)

## Learning Objectives
- [ ] Understand the 3n+1 conjecture
- [ ] Implement iterative logic
- [ ] Practice input/output handling in C++

## Solution Approach

### Algorithm Logic
1. Read input values
2. 從i,j中取出最小值開始到最大值結束
    - 區間 [i, j] 中的每個數的 3n+1 cycle length：
        - 若 n 為奇數 → n = 3n + 1
        - 若 n 為偶數 → n = n / 2
        - n==1 時停止
3. Output the result

### Key Insights
- Cycle length 包含起始數字本身
- 輸入可能是 i > j

## Code Structure
```cpp
```
[source code](./src/s1133343-UVa100.cpp)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 一開始看不懂題目不知道是要找兩數中間最大的cycle length
    - 沒考慮i j誰大誰小
- How would you improve this solution?
    - 可以用遞迴寫看看
- What did you learn?
    - 練習暴力解法與優化思維
## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials