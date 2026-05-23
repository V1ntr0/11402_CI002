# UVa 12347 - Binary Search Tree
## Problem Description
已知一棵二元搜尋樹的前序編歷（Preorder）結果，試求該二元搜尋樹的後序遍歷（Postorder）結果。
輸入資料會持續讀入整數直到檔案結束（EOF），且節點總數不超過 10,000 個。

 Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3769)

## Learning Objectives
- [ ] 理解二元搜尋樹的特性：左子樹所有節點值 < 根節點值 < 右子樹所有節點值。
- [ ] 掌握樹的遍歷轉換技巧（如何從 Preorder 尋找分界點直接輸出 Postorder）。
## Solution Approach

### Algorithm Logic
1. 讀入所有資料，將所有測資依序存入 vector<int> nodes 中
2. 定義遞迴邊界：
    - 函式buildpost(l, r)代表處理nodes[l]到nodes[r]區間內的子樹。若 l > r，表示該子樹為空，直接return。
3. 找到根節點(Preorder 的第一個元素 nodes[l] 一定是當前子樹的根節點)
4. 劃分左右子樹：
    - 從 l + 1 開始往後掃描，只要節點值小於 root，就屬於左子樹。當遇到第一個大於 root 的節點（index為 p）時，區間被劃分為：
        - 左子樹區間：[l + 1, p - 1]
        - 右子樹區間：[p, r]
5. 後序輸出：
    - 遵循後序遍歷「左->右->根」的順序，先遞迴呼叫左子樹 buildpost(l + 1, p - 1)，再遞迴呼叫右子樹 buildpost(p, r)，最後印出當前的 root。

### Key Insights
- 不需要在記憶體中真正宣告 struct Node 並把樹建出來。可以直接利用 Preorder 序列的數值大小直接推導出左右子樹的邊界。
## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
vector<int>nodes;
void buildpost(int l,int r){
    if(l>r)
        return;
    int root=nodes[l];
    int p=l+1;
    while(p<=r&&root>nodes[p])
        p++;
    buildpost(l+1,p-1);
    buildpost(p,r);
    cout<<root<<endl;

}
int main(){
    int value;
    while(cin>>value){
        nodes.push_back(value);
    }
    if(!nodes.empty())
        buildpost(0,nodes.size()-1);

}

//pre�����k post�����k

```
[source code](./src/s1133343-UVa12347.cpp)

## Complexity Analysis
- **Time Complexity:** O(NlogN)
- **Space Complexity:** O(N^2)

## Notes & Reflection
- What challenges did you face?
    - 有點忘記怎麼寫後序輸出的遞迴
- How would you improve this solution?
    - 
- What did you learn?
    - 複習前序遍歷（根->左->右）與後序遍歷（左->右->根）的遞迴對應。

## References
- [Problem Link](https://onlinejudge.org/)
- Related concepts or tutorials