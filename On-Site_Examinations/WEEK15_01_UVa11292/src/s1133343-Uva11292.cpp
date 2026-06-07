#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m&&(n!=0||m!=0)){
        if(n>m){
             cout<<"Loowater is doomed!"<<endl;
             break;
        }
        int dragon[n],knight[m];
        for(int a=0;a<n;a++)
            cin>>dragon[a];
        for(int a=0;a<m;a++)
            cin>>knight[a];
        sort(dragon,dragon+n);
        sort(knight,knight+m);

        int cost=0;
        int i,j;
        for( i=0,j=0;j<n&&i<m; ){
            if(knight[i]>=dragon[j]){
                dragon[j]=0;
                cost+=knight[i];
                i++;
                j++;

            }else{
                i++;
            }
        }
        bool died=true;
        for(int z=0;z<n;z++){
            if(dragon[z]>0){
                died=false;
                break;
            }
        }
        if(died){
            cout<<cost<<endl;
        }
        else
            cout<<"Loowater is doomed!"<<endl;
    }

}

