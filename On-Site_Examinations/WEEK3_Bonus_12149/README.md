
# UVa 12149 - Feynman
## Problem Description
給定一個整數 n，代表一個 n × n 的方格。
問題是：
    在這個 n × n 的格子中，一共有多少個正方形？
輸入會有多組 n，當 n = 0 時結束。
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3301)

## Learning Objectives
- [ ] 理解 平方數累加 (Sum of Squares)
- [ ] 練習 多組輸入 (EOF / sentinel input)
- [ ] 練習 for 迴圈累加
- [ ] 學習 數學公式優化
## Solution Approach

### Algorithm Logic
1. 不斷讀入 n
2. 如果 n == 0 → 結束程式
3. 初始化 sum = 0
4. 從 1 到 n
5. 每次累加 i × i
6. 輸出 sum

### Key Insights
在 n × n 的格子中：
- 1 × 1 正方形有 n² 個
- 2 × 2 正方形有 (n-1)² 個
- 3 × 3 正方形有 (n-2)² 個
- ...
- n × n 正方形有 1 個

## Code Structure
```cpp
#include <iostream>
using namespace std;
//1*1�Ҧ�����l�Ʒ|�bn*n��X��
int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i * i;
		}
		cout << sum <<endl;
	}
	//8: 1:64 2:

}
```
[source code](./src/s1133343-UVa12149-Bonus)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 理解題目其實是在問 所有大小正方形的數量
    - 需要想到 平方數累加
- How would you improve this solution?
    - 可以使用 平方和公式​
- What did you learn?
    - n × n 方格中的正方形數量問題
    - 平方和公式
    - 多組輸入的處理方式

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials