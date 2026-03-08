
# UVa 490 - Rotating Sentences

## Problem Description
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=431)

## Learning Objectives
- [ ] Understand 
- [ ] Implement 
- [ ] Practice input/output handling in C++

## Solution Approach

### Algorithm Logic
1. 使用 getline() 讀取輸入的每一行文字，並存入 text 陣列中
2. 記錄所有行中 最長的字串長度 (length)
3. 當輸入結束後，開始進行旋轉輸出：
	- 外層迴圈從 0 到 length - 1，代表旋轉後的每一行。
	- 內層迴圈從 最後一行往第一行 掃描
4. 如果目前字串長度大於索引位置 i，輸出該字元
5. 如果該位置不存在字元，則輸出空白 " "
6. 每完成一列輸出後換行

### Key Insights
- 不同輸入行的 字串長度可能不同，因此必須記錄最長字串長度
- 旋轉 90 度時：
	- 原本的 行變成列
	- 輸出順序必須 從最後一行往上輸出
- 當某行字串長度不足時，需要輸出 空格 來維持對齊
- 使用 getline() 可以保留空格與整行內容

## Code Structure
```cpp
#include<iostream>
#include<string>
using namespace std;
int main() {
	string text[101];
	int length=0;
	int index = 0;
	/*�����̤j���r�ơA�íp���`���*/
	while (getline(cin, text[index])) {
		if (length < text[index].length())
			length = text[index].length();
		index++;
	}
	/*�ѳ̫�@�C���Ĥ@�C��X�A�A�ѲĤ@�r���̫�@�r��X�A����p�G�S���r�F�ɪŮ�*/
	for (int i = 0; i < length; i++) {
		for (int j = index - 1; j >= 0; j--) {
			if (text[j].length() > i)
				cout << text[j][i];
			else
				cout << " ";
		}
		cout << endl;
	}
}
```
[source code](./src/s1133343-UVa490)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** O(?)

## Notes & Reflection
- What challenges did you face?
	- 一開始忘記開如何結束輸入
- How would you improve this solution?
	- 可以使用 vector<string> 取代固定大小的陣列
- What did you learn?
	- 使用ctrl+Z可以直接結束輸入

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials