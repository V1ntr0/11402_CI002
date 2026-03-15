
# UVa 10783 - Odd Sum
## Problem Description
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1724)

## Learning Objectives
- [ ] Understand 
- [ ] Implement 
- [ ] Practice input/output handling in C++

## Solution Approach

### Algorithm Logic
1. Read input values
2. 
3. Output the result

### Key Insights
- 

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
    - 
- How would you improve this solution?
    - 
- What did you learn?
    - 

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials