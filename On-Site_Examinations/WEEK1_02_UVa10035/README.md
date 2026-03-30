
# UVa 10035 - Primary Arithmetic

## Problem Description
給兩個非負整數(低於10位數)，計算在直式加法中進位次數
當輸入 0 0 時結束程式。
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=976)

## Learning Objectives
- [ ] Understand the Primary Arithmetic conjecture
- [ ] Implement iterative logic
- [ ] Practice input/output handling in C++

## Solution Approach

### Algorithm Logic
1. Read input values
2. 若兩者皆為 "0" → 結束
3. 從個位數開始計算
    - 若相加>10時，進位次數+1，並暫存進位的數字(除10)
4. 兩數皆除10，回到第3步直到兩數相加完畢
5. Output the result

### Key Insights
- 輸出有3種格式，單數複數是不一樣的
- 相加要全部數字加完，不能其中一個加完就停止(例如:99+1)

## Code Structure
```cpp
#include <iostream>
using namespace std;
int main() {
	int i, j;
	while (cin >> i >> j) {//輸入i,j，直到輸入為0 0時結束
		if (i == 0 && j == 0)
			break;
		int carry = 0,temp=0;
		while (i > 0 || j > 0 ||temp > 0) {//數字都=0結束
			int s = i % 10 + j % 10+temp;//s計算有沒有進位(把兩個數最後一個數字相加+進位的數字)
			if (s >= 10)//如果要進位carry+1
				carry++;
			//兩個數字除10，進行下一位數進位，temp是進位的數字(s)除10
			temp = s / 10;
			i /= 10;
			j /= 10;
		}
		//輸出進位次數
		if (carry == 0)
			cout << "No carry operation."<<endl;
		else if(carry == 1)
			cout << carry << " carry operation." << endl;
		else
			cout << carry << " carry operations."<<endl;
	}
	return 0;
}
```
[source code](./src/s1133343-UVa10035.cpp)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 一開始寫 i>0&&j>0 導致錯誤
- How would you improve this solution?
- What did you learn?

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials
