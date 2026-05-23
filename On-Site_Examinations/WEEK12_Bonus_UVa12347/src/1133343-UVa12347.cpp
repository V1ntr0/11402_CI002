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

//pre¤¤¥ª¥k post¥ª¤¤¥k

