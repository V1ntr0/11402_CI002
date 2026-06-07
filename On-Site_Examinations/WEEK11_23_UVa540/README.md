# UVa 540 - Team Queue
## Problem Description
這是一個模擬「團隊排隊」的問題。規則類似於現實生活中與朋友一起排隊的情境：當一個人準備排隊時，如果發現隊伍中已經有自己的隊友，他就可以直接插隊到隊友的最後方；如果隊伍中沒有任何隊友，他就必須乖乖排到整個隊伍的最尾端。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=481)

## Learning Objectives
- [ ] 學習如何將多種資料結構（queue, map, vector）組合應用以解決複雜的模擬問題。
- [ ] 熟悉Queues 的實作
## Solution Approach

### Algorithm Logic
1. 讀入整數 t (代表團隊數量)，若 t 為 0 則結束程式
2. 利用 map<int, int> 讀入每個團隊的成員，並將每個「人員 ID」對應到其所屬的「團隊 ID」
3. 建立一個主隊列 mainqueue 用來記錄「目前有哪些團隊在排隊」
4. 建立一個子隊列 teamqueue 來記錄「每個團隊內部的排隊順序」
5. 用布林陣列 isteaminqueue 追蹤某團隊是否已在主隊列中
6. 讀取輸入指令
    - ENQUEUE 指令:
        - 讀入人員 ID，查出其團隊 ID。
            - 若該團隊尚未在主隊列中，則將該團隊 ID 推入主隊列，並標記為 true。
        - 將該人員推入其專屬的團隊子隊列中。
    - DEQUEUE 指令：
        - 查看主隊列最前方的團隊 ID，並從該團隊的子隊列中pop（輸出）最前面的一員。
        - 若pop後該團隊的子隊列變為空
            - 將該團隊 ID 從主隊列中彈出，並將其標記改為 false。
    - STOP 指令 :
        - 跳出執行下一測資
### Key Insights
- 雙層佇列設計：只用單一佇列不好操作。透過「主隊列管團隊順序」與「子隊列管團隊內部成員順序」的拆解，可以完美模擬且保持高效。
- 狀態追蹤陣列：使用 isteaminqueue 陣列能快速判斷一個團隊是否已經有人在排隊，避免遍歷主隊列。
## Code Structure
```cpp
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int main(){
    int t,casenum=1;
    while(cin>>t&&t!=0){
        cout<<"Scenario #"<<casenum++<<endl;
        map<int,int>persontoteam;
        for(int i=0;i<t;i++){
            int n;
            cin>>n;

            while(n--){
                int person;
                cin>>person;
                persontoteam[person]=i;
            }
        }
        queue<int>mainqueue;
        vector<queue<int>>teamqueue(t);
        vector<bool>isteaminqueue(t,false);

        string cmd;
        while(cin>>cmd&&cmd!="STOP"){
            if(cmd=="ENQUEUE"){
                int person;
                cin>>person;
                int teamid= persontoteam[person];
                if(!isteaminqueue[teamid]){
                    mainqueue.push(teamid);
                    isteaminqueue[teamid]=true;
                }
                teamqueue[teamid].push(person);
            }
            else if(cmd=="DEQUEUE"){
                int teamid=mainqueue.front();
                cout<<teamqueue[teamid].front()<<endl;
                teamqueue[teamid].pop();

                if(teamqueue[teamid].empty()){
                    isteaminqueue[teamid]=false;
                    mainqueue.pop();
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

```
[source code](./src/s1133343-UVa540.cpp)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** O(?)

## Notes & Reflection
- What challenges did you face?
    - 一開始在單一 queue 甚至 vector 中尋找隊友並直接插入
    - 忘記在每次測資開始時（while 迴圈內）重新宣告/初始化所有資料結構（如 mainqueue, teamqueue, isteaminqueue）。
- How would you improve this solution?
    - 
- What did you learn?
    - 學習到了如何利用分層管理的概念來解決具有群組特性的排隊問題

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials