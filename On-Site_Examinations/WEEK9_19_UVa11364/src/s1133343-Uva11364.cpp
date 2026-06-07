#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int max_pos=-1;
        int min_pos=100;
        for(int i=0;i<n;i++){
            int pos;
            cin>>pos;
            if(pos<min_pos)
                min_pos=pos;
            if(pos>max_pos)
                max_pos=pos;
        }
        cout<<( max_pos - min_pos) *2<<endl;
    }
}
