#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    int n,q,target;
    int casenum=1;
    while(cin>>n>>q&&(n!=0||q!=0)){
        int marble[n]{};
        for(int i=0;i<n;i++)
            cin>>marble[i];
        sort(marble,marble+n);
        cout<<"CASE# "<<casenum++<<":"<<endl;

        while(q--){
            cin>>target;
            int ans=-1;
            int left=0,right=n-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(marble[mid]==target){
                    ans=mid;
                    //break;
                }
                if(marble[mid]<target){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            if(ans>=0){
                cout<<target<<" found at "<<ans+1<<endl;
            }
            else{
                cout<<target<<" not found"<<endl;
            }
        }

    }


}
