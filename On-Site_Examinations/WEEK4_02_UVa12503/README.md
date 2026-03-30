
# UVa 12503 - RobotInstructions
## Problem Description
給定一個機器人站在位置 0，會接收一系列指令：

"LEFT"：向左移動（-1）
"RIGHT"：向右移動（+1）
"SAME AS i"：執行第 i 個指令

計算所有指令執行完後，輸出機器人的最終位置。
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3947)

## Learning Objectives
- [ ] 理解字串輸入與條件判斷
- [ ] 練習使用陣列/向量記錄歷史指令
- [ ] 熟悉模擬（Simulation）問題解法

## Solution Approach

### Algorithm Logic
1. 讀入測資數量 t
2. 對每組測資：
	1. 讀入指令數 n
	2. 建立 history 陣列記錄每一步的移動（+1 或 -1）
	3. 逐行讀入指令：
		- 若是 "LEFT" → 記為 -1
		- 若是 "RIGHT" → 記為 +1
		- 若是 "SAME AS i" → 記為 history[i-1]
	4. 每一步累加位置變化 
3. 輸出最終位置

### Key Insights
在 n × n 的格子中：
- 必須記住每一步的結果
- "SAME AS i" 是直接引用之前的結果
- 不需要真的「回頭執行」，只要存數值即可

## Code Structure
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	if (t <= 0) return 0;
	while ( t--) {
			int a = 0;
			cin >> n;

			vector<int> history(n+1);
			
			for (int i = 0; i < n; i++){
				string s;
				cin>>s;
				if (s == "RIGHT") {
					history[i] = 1;
				}
				else if (s == "LEFT") {
					history[i] = -1;
				}
				else {
					string junk; 
					int num=0;
					cin >> junk >> num; 
					history[i] = history[num - 1];
				}
				a += history[i];
			}
			cout << a << endl;
			
	}
	return 0;
}

```
[source code](./src/s1133343-UVa12503)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 一直RE，改了很多版還是一樣
- How would you improve this solution?
    - 可以改用 int history[100]（因為 n 很小）減少 vector 開銷
- What did you learn?
    - 模擬題的核心：把狀態記錄下來
    - 多組輸入的處理方式

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials