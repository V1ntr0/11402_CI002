#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m&&(n!=0||m!=0)){
        if(n>m){
             cout<<"Loowater is doomed!"<<endl;
             continue;
        }
        int dragon[n],knight[m];
        for(int a=0;a<n;a++)
            cin>>dragon[a];
        for(int a=0;a<m;a++)
            cin>>knight[a];
        sort(dragon,dragon+n);
        sort(knight,knight+m);

        int cost=0;
        int i=0,j=0;
        while (i < n && j < m) {
            if (knight[j] >= dragon[i]) {
                cost += knight[j];
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == n)
            cout<<cost<<endl;
        else
            cout<<"Loowater is doomed!"<<endl;
    }

}

