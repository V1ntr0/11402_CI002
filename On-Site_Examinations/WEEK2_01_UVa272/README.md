
# UVa 272 - TEX Quotes

## Problem Description
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208)

## Learning Objectives
- [ ] Understand 
- [ ] Implement 
- [ ] Practice input/output handling in C++

## Solution Approach

### Algorithm Logic
1. 使用 cin.get() 持續讀取輸入中的每一個字元
2. 檢查目前讀到的字元是否為雙引號 "
3. 如果是第一個引號，輸出 ``
4. 如果是第二個引號，輸出 '' 
5. 每次遇到 " 時切換 check 的狀態
6. 如果讀到的不是 "，則直接輸出該字元
7. 重複上述步驟直到輸入結束
### Key Insights
- 題目的輸入可能包含 多行文字，因此需要持續讀取直到 EOF (End of File)。
- 每一個 " 必須 交替轉換：
	- 第一個 " → ``
	- 第二個 " → ''
- 使用 cin.get() 可逐字讀取輸入，方便判斷並替換特定字元。
- 使用一個變數 check 來記錄目前應該輸出的是 ``還是''。

## Code Structure
```cpp
#include <iostream>
using namespace std;

int main() {
	int check = 1;
	char text;
	while (cin.get(text)) {
		//�J��Ĥ@�Ӥ޸��ɡA��X``�A�J��ĤG�Ӥ޸���X''�Ccheck�O���Ĥ@���٬O�ĤG�Ӥ޸�
		if (text == '"') {
			if (check == 1)
				cout << "``";
			else
				cout << "''";
			check = (check + 1) % 2;
		}
		else
			cout << text;
	}
}
```
[source code](./src/s1133343-UVa272.cpp)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
	- 一開始不知道該用char還是string
- How would you improve this solution?
	- 可以將 check 由 int 改成 bool，讓程式語意更清楚
- What did you learn?
	- 比較理解甚麼時候用char,string

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials