
# UVa 10170 - The Hotel with Infinite Rooms

## Problem Description
有一家房間無限多的旅館。
- 第 s 天會有 s 位客人入住
- 第 s+1 天會有 s+1 位客人入住
- 第 s+2 天會有 s+2 位客人入住
- 依此類推，每天入住的人數會增加 1
給定兩個數：
- s：開始的天數（當天有 s 位客人）
- d：需要安排的總客人人數
問題是：
第 d 位客人會在第幾天入住？
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1111)

## Learning Objectives
- [ ] Understand simulation with cumulative sums
- [ ] Implement while-loop accumulation logic 
- [ ] Practice input/output handling in C++

## Solution Approach

### Algorithm Logic
1. Read input values
2. 模擬每天入住的人數
3. 每一天的客人數量為 s
4. 將 d 減去當天入住人數
5. 如果 d <= 0，代表第 d 位客人就在這一天
6.  Output the result

### Key Insights
- 訪客人數每天呈線性增長。
- 我們持續從每日抵達人數中扣除，直到算到第 d 位客人為止。
- 必須使用 long long，因為數字可能會變得很大。
- 輸入在 EOF 處結束，因此我們使用 while(cin >> s >> d)。

## Code Structure
```cpp
#include <iostream>
using namespace std;
int main() {
	long long s, d,sum;
	while (cin >> s >> d) {
		while (d > 0) {
			d -= s;
			if (d <= 0) break;
			s++;
		}
		cout << s<<endl;
	}
}
```
[source code](./src/s1133343-UVa10170)

## Complexity Analysis
- **Time Complexity:** O(√d)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 理解題目其實是 找累加何時超過 d
- How would you improve this solution?
    - 可以用 數學公式（等差級數）直接計算
- What did you learn?
    - 使用long long 避免 overflow
	- EOF 輸入處理

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials