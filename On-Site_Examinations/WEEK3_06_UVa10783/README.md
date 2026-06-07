
# UVa 10783 - Odd Sum
## Problem Description
給定一個整數 T 代表測試資料數量。
每組測試資料會給兩個整數 a 和 b。
- 計算區間 [a, b] 之間所有奇數的總和。
輸出格式必須為：
- Case X: sum
其中 X 是測試案例編號（從 1 開始）。
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1724)

## Learning Objectives
- [ ] 理解 區間遍歷 (range iteration)
- [ ] 熟悉 for / while 迴圈
- [ ] 練習 奇偶數判斷 (% 2)
- [ ] 練習 多組輸入輸出格式

## Solution Approach

### Algorithm Logic
1. 讀入測試資料數 T
2. 對每一組資料：
    - 讀入 a 和 b
3. 在區間 [a, b] 中找出所有 奇數
4. 將奇數累加到 sum
5. 依照格式輸出結果

### Key Insights
- 如果 a 是偶數
    - → 先 a += 1 變成奇數
- 之後每次 +2，只遍歷奇數


## Code Structure
```cpp
#include <iostream>
using namespace std;
int main() {
	int T, a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int sum = 0;
		cin >> a >> b;
		while (a <= b) {
			if (a % 2 == 0) {
				a += 1;
				continue;
			}
			sum += a;
			a += 2;
		}
		cout << "Case " << i + 1 <<": " << sum<<endl;
	}
}
```
[source code](./src/s1133343-UVa10783)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** O(?)

## Notes & Reflection
- What challenges did you face?
    - 一開始寫if else 把sum加法包在else裡面，導致會少加第一項
- How would you improve this solution?
    - 把判斷是否為奇偶,移到while前面
- What did you learn?
    - 區間問題常見兩種做法：
		- 迴圈累加
		- 數學公式
	- 使用 % 2 判斷奇偶


## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials