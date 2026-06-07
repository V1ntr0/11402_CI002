
# UVa 10931 - Parity
## Problem Description
給定一個正整數 n（0 結束），將其轉換成二進位表示，並計算其中 1 的個數（即 parity）。輸出該二進位字串與 1 的數量。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1872)

## Learning Objectives
- [ ] 熟悉十進位轉二進位的方法
- [ ] 理解 parity（位元中 1 的數量）概念
## Solution Approach

### Algorithm Logic
1. 讀入整數 n
2. 若 n == 0，結束程式
3. 使用除以 2 的方式將 n 轉換成二進位字串
4. 在轉換過程中統計 1 的數量（parity）
5. 將結果反轉（因為是從低位元開始建構）
6. 輸出格式化結果

### Key Insights
- 十進位轉二進位可以透過「不斷除以 2 取餘數」來完成
- parity 就是二進位表示中 1 的個數
- 字串需要反轉，因為最低位元會先被處理

## Code Structure
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i;
    while(cin>>i&&i!=0){
        string s;
        int count=0;
        while(i>0){

            if(i%2==1){
                s+='1';
                count++;

            }
            else{
                s+='0';
            }

            i/=2;
        }
        reverse(s.begin(),s.end());
        cout<<"The parity of "<<s<<" is "<<count<<" (mod 2)."<<endl;
  }
}

```
[source code](./src/s1133343-UVa10931)

## Complexity Analysis
- **Time Complexity:** O(log n)
- **Space Complexity:** O(log n)

## Notes & Reflection
- What challenges did you face?
    - 一開始忘記需要 reverse 字串
- How would you improve this solution?
    - 若不需要字串，其實可以只計算 parity，節省空間
- What did you learn?
    - 熟悉位元操作與數字轉換技巧
    - 理解 parity 在電腦科學中的應用（例如錯誤檢測）


## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials