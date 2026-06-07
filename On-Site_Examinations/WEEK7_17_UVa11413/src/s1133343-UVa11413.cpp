#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
bool check(int cap){
    int used=1,capacity=0;
    for(int i=0;i<n;i++){
        if(capacity+a[i]>cap){
            used++;
            capacity=a[i];
        }
        else{
            capacity+=a[i];
        }
    }
    return m>=used;
}
int main(){
    while(cin>>n>>m){
        int ans=-1;
        int mx=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
            sum+=a[i];
        }
        int low=mx,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        cout<<ans<<endl;
    }

}

