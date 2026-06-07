#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    int n,b[105],casenum=1;
    while(cin>>n){
        bool isb2=true;
        for(int i=0;i<n;i++){
            cin>>b[i];
        if(b[i]<1||(i>0&&b[i]<=b[i-1]))
            isb2=false;
        }
        if(isb2){
            vector<int> sums;
            for(int i=0;i<n;i++)
                for(int j=i;j<n;j++)
                    sums.push_back(b[i]+b[j]);
            sort(sums.begin(),sums.end());
            for(int i=0;i<(int)sums.size()-1;i++)
                if(sums[i]==sums[i+1]){
                isb2=false;
                break;
                }
        }
        cout<<"Case #"<<casenum++<<":"<<(isb2?" It is a B2-Sequence.":" It is not a B2-Sequence.")<<endl<<endl;
    }
}
