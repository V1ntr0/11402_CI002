#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int r;
        cin>>r;
        vector<int> s(r);
        for(int i=0;i<r;i++){
            cin>>s[i];
        }
        sort(s.begin(),s.end());
        int d=0;
        int mid=s[r/2];

        for(int i=0;i<r;i++){
            d+=abs(mid-s[i]);
        }
        cout<<d<<endl;
    }


}
