# UVa 1062 - Containers
## Problem Description
給定一個只包含大寫英文字母的字串，依序將每個字母放入「container stacks」。
規則：
- 每個 stack 的頂端字母必須 ≥ 新字母 才能放上去
- 否則就要開一個新的 stack
目標：使用最少的 stacks 數量

輸入多組資料，直到讀到 "end" 為止。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=628&page=show_problem&problem=3503)

## Learning Objectives
- [ ] 模擬stack的應用
- [ ] Greedy 演算法
## Solution Approach

### Algorithm Logic
1. 讀入字串 s
2. 建立一個 vector<char> st 代表每個 stack 的「頂端字母」
3. 對於每個字元 c：
    - 在所有 stack 中找一個 頂端 ≥ c 且最小的
        - 如果找到：
            - 把該 stack 的頂端更新為 c
        - 如果找不到：
            - 新開一個 stack（push_back）
4. 輸出 stack 數量 st.size()
5. 重複直到輸入為 "end"

### Key Insights
- 每次選「最適合」的 stack（頂端最小但 ≥ c）
- 可以讓後續字母有更多空間放入
## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int casenum=1;
     while(cin>>s&&s!="end"){
        vector<char> st;
        for(char c:s){
            int beststack =-1;
            char mintop='{';
            for(int i=0;i<st.size();++i)
                if(st[i]>=c){
                    if(st[i]<mintop){
                        mintop=st[i];
                        beststack=i;
                    }
                }
            if(beststack!=-1)
                st[beststack]=c;
            else
                st.push_back(c);
        }
        cout<<"Case "<<casenum++<<": "<<st.size()<<endl;
    }
}
```
[source code](./src/s1133343-UVa1062.cpp)

## Complexity Analysis
- **Time Complexity:** O(n²)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 一開始不理解為什麼是「找最小 ≥ c」
- How would you improve this solution?
    - 
- What did you learn?
    - 利用vector模擬stack

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials