
# UVa 299 - Train Swapping
## Problem Description
給你一列火車車廂的排列順序，每次只能交換相鄰兩節車廂。
請問最少需要幾次交換，才能讓車廂按照編號由小到大排序。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=235)

## Learning Objectives
- [ ] 理解 Bubble Sort 的交換次數意義
- [ ] 練習模擬排序過程與計數

## Solution Approach

### Algorithm Logic
1. 不斷讀入 n
2. 對每筆測資：
    - 讀入車廂數量 l
    - 讀入車廂排列
3. 使用 Bubble Sort
    - 每當 train[i] > train[i+1] 就交換
    - 並累加 count++
4. 輸出交換次數(count)

### Key Insights
- Bubble Sort 剛好會做「最少必要交換」
- 
## Code Structure
```cpp
#include <iostream>
using namespace std;
int main() {
	int n, l=0;
	cin >> n;
	int i, j;
	while (n > 0) {
		cin >> l;
		int train[l]{},count = 0;
		for (i = 0; i < l; i++) {
			cin>>train[i];
		}
		for (int a = 0; a < l; a++) {
			for (int b = 0; b < l-a-1;b++) {
				if (train[b] > train[b + 1]){
					swap(train[b], train[b + 1]);
					count++;
				}
			}
		}
		cout << "Optimal train swapping takes " << count << " swaps." << endl;
		n--;
	}
}
```
[source code](./src/s1133343-UVa299)

## Complexity Analysis
- **Time Complexity:** O(n²)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 不確定「最少交換次數」怎麼算
- How would you improve this solution?
    - 
- What did you learn?
    - Bubble Sort 不只是排序，也能用來：
        -  計算 inversion


## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials