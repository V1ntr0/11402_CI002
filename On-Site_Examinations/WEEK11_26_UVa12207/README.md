
# UVa 12207 - That is Your Queue
## Problem Description
有一個隊列，裡面有 P 個人（編號 1 到 P）。
有兩種指令：
1. N (Next)：取出隊列最前面的人，處理完後將他移到隊列最後面。
2. E x (Expedite)：編號為 x 的人享有特權，直接插隊到整個隊列的最前面。如果 x 本來就在隊列中，他會移動到最前方。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3359)

## Learning Objectives
- [ ] 練習 deque 的雙端操作：push_front, push_back, pop_front。
- [ ] 學習如何在容器中搜尋特定元素並移除（erase）
## Solution Approach

### Algorithm Logic
1. 讀入整數 P (人數) 與 C (指令數)：若兩者皆為 0 則結束。
2. 取前 min(P, C) 個人初始化隊列
3. 處理 N 指令：
    - 輸出 dp.front()。
    - 將最前面的人取出 (pop_front)，再推入末端 (push_back)。
4. 處理 E x 指令：
    - 在隊列中尋找編號為 $x$ 的人，如果找到了就將其移除（erase）。將 x 推入隊列的最前端 (push_front)。

### Key Insights
- 如果直接開 10^9 的空間會記憶體崩潰。但因為最多只有 C 次指令，即便每次都是 N 指令，也只有前 C 個人會被用到。所以初始化時取 min(P, C) 即可。
- deque 支援 push_front，非常適合處理「插隊」的需求。
## Code Structure
```cpp
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;
int main(){
    int p,c,casenum=1;
    while(cin>>p>>c&&(p!=0&&c!=0)){
        cout<<"Case "<<casenum++<<":"<<endl;
        deque<int>dp;
        int count=min(p,c);
        for(int i=1;i<=count;i++){
            dp.push_back(i);
        }
        while(c--){
            char cmd;
            cin>>cmd;
            if(cmd=='N'){
                int front=dp.front();
                cout<<dp.front()<<endl;
                dp.pop_front();
                dp.push_back(front);
            }
            else if(cmd=='E'){
                int x;
                cin>>x;
                for(auto it=dp.begin();it!=dp.end();++it){
                    if(*it==x){
                        dp.erase(it);
                        break;
                    }
                }
                dp.push_front(x);
            }
        }
    }
}

```
[source code](./src/s1133343-UVa12207.cpp)

## Complexity Analysis
- **Time Complexity:** O(C * min(P, C))
- **Space Complexity:** O(min(P, C))

## Notes & Reflection
- What challenges did you face?
    - 不太確定erase用法
- How would you improve this solution?
    - 如果C非常大，O(C^2) 可能會慢。可以使用 list 搭配 unordered_map 來記錄每個編號在 list 中的位置。
- What did you learn?
    - 學習到「縮小問題範圍」的重要性。不需要處理所有資料，只需要處理「可能被影響」的資料。
    - 熟悉了 deque 的 erase 操作。

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials