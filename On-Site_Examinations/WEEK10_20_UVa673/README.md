# UVa 673 - Parentheses Balance
## Problem Description
給定多行字串，每一行只包含：
- 小括號 ( )
- 中括號 [ ]
- 空行
判斷每一行的括號是否「平衡」。
平衡條件：
- 左右括號數量正確
- 括號順序正確（不能交錯錯配）

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614)

## Learning Objectives
- [ ] Stack 基本應用
- [ ] 括號匹配
## Solution Approach

### Algorithm Logic
1. 讀入整數 n
2. 逐行讀入字串（使用 getline）
3. 對每一行：
    - 建立一個 stack
4. 對每個字元 c：
    - 如果是左括號 ( 或 [ → push
    - 如果是右括號：
        - 若 stack 為空 → 不合法
        - 若 top 不匹配 → 不合法
        - 否則 pop
5. 輸出
    - stack 為空 → 合法（Yes）
    - 否則 → 不合法（No）

### Key Insights
- Stack 完全對應「括號的巢狀結構」
- 最後開的括號要最先關（LIFO）
## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
bool isv(string s){
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='['){
            st.push(c);
        }
        else if(c==')'||c==']'){
            if(st.empty())
                return false;
            if(c==')'&&st.top()!='(')
                return false;
            if(c==']'&&st.top()!='[')
                return false;
            st.pop();
        }
    }
    return st.empty();
}
int main(){
    int n;
    string s;
    cin>>n;
    cin.ignore();
    while(n--){
        getline(cin,s);
        if(isv(s))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

}

```
[source code](./src/s1133343-UVa673.cpp)

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Notes & Reflection
- What challenges did you face?
    - 一開始容易忽略空字串的情況
    - 忘記檢查 stack 為空就取 top
- How would you improve this solution?
    - 可以把匹配條件寫成 function
- What did you learn?
    - Stack 是處理「配對 / 巢狀結構」的標準工具

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials