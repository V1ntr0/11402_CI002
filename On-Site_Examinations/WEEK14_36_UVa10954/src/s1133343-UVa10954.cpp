#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n!=0){
        priority_queue <int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            pq.push(num);
        }
        int totalcost=0;

        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            int sum=first+second;
            totalcost+=sum;
            pq.push(sum);
        }
        cout<<totalcost<<endl;

    }


}
