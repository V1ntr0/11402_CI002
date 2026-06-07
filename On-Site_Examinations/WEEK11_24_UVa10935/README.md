# UVa 10935 - Throwing cards away I
## Problem Description
桌上有 n 張牌，編號從 1 到 n（1 在最上面）。只要牌堆中至少還有兩張牌，就重複執行以下動作：
丟掉最上面的牌。把現在最上面的牌放到牌堆的最下面。
最後要印出丟掉的牌順序，以及最後剩下的那張牌。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876)

## Learning Objectives
- [ ] 了解 queue 的基本操作：push, pop, front, size。
- [ ] 學習如何模擬循環結構
## Solution Approach

### Algorithm Logic
1. 讀入整數 n,若 n=0 則停止。
2. 將 1 到 n 依序推入 queue 中，模擬原本的牌堆。
3. queue 的長度大於 1 時，執行循環：
    - 取出最前端元素，存入 discarded 向量，並從 queue 中移除（丟牌）。
    - 再次取出目前最前端元素，將其推入 queue 的尾端，並從前端移除（移動到牌底）。
4. 印出丟棄的卡片編號與最後剩下的卡片。

### Key Insights
- 這題的動作（拿走頂端、放到末端）完全對應佇列的 pop() 和 push()，不需要複雜的陣列位移。
- 當 n=1 時，丟棄的卡片列表為空，輸出 Discarded cards: 後面不應有空格或逗號。
## Code Structure
```cpp
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int main(){
    int n;
    while(cin>>n&&n!=0){
        queue<int> cards;
        for(int i=1;i<=n;i++)
            cards.push(i);
        vector<int> discarded;
        while(cards.size()>1){
            discarded.push_back(cards.front());
            cards.pop();

            int top=cards.front();
            cards.pop();
            cards.push(top);
        }
        cout<<"Discarded cards:";
        for(int i=0;i<discarded.size();i++){
            cout<<" "<<discarded[i];
            if(i!=discarded.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
        cout<<"Remaining card: "<<cards.front()<<endl;
    }
}

```
[source code](./src/s1133343-UVa10935.cpp)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 逗號只能放在兩個數字之間，最後一個數字後面不能有逗號。
    - 當 $n=1$ 時，迴圈不會執行，輸出必須保持正確。
- How would you improve this solution?
    - 其實不需要 vector 存丟掉的牌，可以在 pop 的同時直接印出，這樣空間複雜度可以降到更低。
- What did you learn?
    - 更加熟悉了模擬題的流程：分析規則 -> 選擇數據結構 -> 處理邊界條件。
    
## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials