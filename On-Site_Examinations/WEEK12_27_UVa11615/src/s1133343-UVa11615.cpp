#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int t;
    int n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        int total=(2^n)-1;
        int da=log2(a)+1;
        int db=log2(b)+1;
        int max_d=max(da,db);
        int sub_h=n-max_d+1;
        int sub_nodes=(2^sub_h)-1;
        cout<<total-sub_nodes+1<<endl;
    }

}

