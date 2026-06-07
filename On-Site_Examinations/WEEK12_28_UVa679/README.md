# UVa 679 - Dropping Balls

## Problem Description
有一棵最大深度為 D 的滿二元樹，所有葉子節點都在第 D 層。
每個節點上都有一個開關，初始狀態全為 false（表示球掉落時會往左走，並將開關切換為 true）。若開關為 true，則球掉落時會往右走，並將開關切換為 false。
現在從根節點（編號 1）依序掉落 I 顆球，試求第 I 顆球最後落到第 D 層時的節點編號。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=620)

## Learning Objectives
- [ ] 理解二元樹的陣列索引表示法（左子節點為 2*pos，右子節點為 2*pos+1）
## Solution Approach

### Algorithm Logic
1. 讀入測試筆數l
2. 讀入D、I
3. 直接目前節點:
    - 如果當前的 I 是奇數：代表它是通過這個節點的第奇數顆球。此時節點狀態必定是 false，所以這顆球會往左子節點走（pos = pos * 2）。而對於左子節點來說，這是流向它的第 (I + 1) / 2 顆球。
    - 如果當前的 I 是偶數：代表它是通過這個節點的第偶數顆球。此時節點狀態已被前一顆球改為 true，所以這顆球會往右子節點走（pos = pos * 2 + 1）。而對於右子節點來說，這是流向它的第 I / 2 顆球。
4. 向下推進 D-1 次，直到球到達第 D 層，輸出最終的 pos。 

### Key Insights
- 每個節點都像是一個分流器，奇數號的球往左送，偶數號的球往右送。因此，我們只需要追蹤第 I 顆球「在下一層是分流到該子樹的第幾顆球」，就能一路直達底部。
## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
long long cnt;
int main(){
    int l;
    while(cin>>l&&l!=-1){
        while(l--){
            int D,I;
            cin>>D>>I;
            int pos=1;
            for(int i=0;i<D-1;i++){
                if(I%2==1){
                    I=(I+1)/2;
                    pos=pos*2;
                }
                else{
                    pos=pos*2+1;
                    I=I/2;
                }
            }
            cout<<pos<<endl;;
        }
    }
}
```
[source code](./src/s1133343-UVa679.cpp)

## Complexity Analysis
- **Time Complexity:** O(D)
- **Space Complexity:** O(1)

## Notes & Reflection
- What challenges did you face?
    - 暴力開陣列去變更 true/false 狀態會因為 I 太大而開銷過高。
- How would you improve this solution?
    - 
- What did you learn?
    - 面對有規律的模擬題，要去推出尋找數學規律

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials