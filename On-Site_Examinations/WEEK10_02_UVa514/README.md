# UVa 514 - Rails
## Problem Description
給定一個火車站，有一條進站軌道（1 → n）以及一個中繼站（stack）。
目標：判斷是否可以透過「一個 stack（車站）」將進站順序 1,2,3,...,n 重新排列成指定的目標序列。

規則：
- 火車依序進站（1 → n）
- 可以：
    - 直接出站
    - 或進入中繼站（stack）
- 中繼站為 LIFO（後進先出）

輸入多組測資，當一組第一個數字為 0 時結束該 n。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455)

## Learning Objectives
- [ ] Stack 模擬
- [ ] 可否由 stack 排列問題
## Solution Approach

### Algorithm Logic
1. 讀入整數 n
2. 不斷讀入目標序列 target
3. 若 target[0] == 0，代表此組結束
4. 使用一個 stack 模擬車站：
    - 設 curr_train = 1
5. 對於每個目標值 target[i]：
    - 持續將火車 push 進 stack，直到：
        - stack.top() == target[i]，或
        - 所有火車已進站
    - 若 stack.top() == target[i]：
        - pop（成功）
    - 否則：
        - 無法完成（標記為 false）
6. 輸出結果 "Yes" 或 "No"
### Key Insights
- 判斷是否為合法的 stack 排列
- 用 stack 模擬暫存軌道
## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n!=0){
        while(true){
            vector<int> target(n);
            cin>>target[0];
            if(target[0]==0)
                break;
            for(int i=1;i<n;i++){
                cin>>target[i];
            }

            stack<int> station;
            int curr_train=1;
            bool poss=true;
            for(int i=0;i<n;i++){
                while(curr_train<=n&&(station.empty()||station.top()!=target[i])){
                    station.push(curr_train++);
                }
                if(!station.empty()&&station.top()==target[i])
                    station.pop();
                else{
                    poss=false;
                    break;
                }
            }
            if(poss)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }
}
```
[source code](./src/s1133343-UVa514.cpp)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 看不懂題目在幹嘛
    - 容易忘記 stack 的限制（只能從頂端取）
- How would you improve this solution?
    - 可以把模擬邏輯抽成函式，提高可讀性
- What did you learn?
    - Stack排列

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials