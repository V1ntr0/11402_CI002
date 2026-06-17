#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int main(){
    int t,casenum=1;
    while(cin>>t&&t!=0){
        cout<<"Scenario #"<<casenum++<<endl;
        map<int,int>persontoteam;
        for(int i=0;i<t;i++){
            int n;
            cin>>n;

            while(n--){
                int person;
                cin>>person;
                persontoteam[person]=i;
            }
        }
        queue<int>mainqueue;
        vector<queue<int>>teamqueue(t);
        vector<bool>isteaminqueue(t,false);

        string cmd;
        while(cin>>cmd&&cmd!="STOP"){
            if(cmd=="ENQUEUE"){
                int person;
                cin>>person;
                int teamid= persontoteam[person];
                if(!isteaminqueue[teamid]){
                    mainqueue.push(teamid);
                    isteaminqueue[teamid]=true;
                }
                teamqueue[teamid].push(person);
            }
            else if(cmd=="DEQUEUE"){
                int teamid=mainqueue.front();
                cout<<teamqueue[teamid].front()<<endl;
                teamqueue[teamid].pop();

                if(teamqueue[teamid].empty()){
                    isteaminqueue[teamid]=false;
                    mainqueue.pop();
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    int T;
    int tc = 1;

    while (cin >> T && T) {

        map<int, int> teamOf;

        for (int i = 0; i < T; i++) {
            int n;
            cin >> n;

            while (n--) {
                int x;
                cin >> x;
                teamOf[x] = i;
            }
        }

        queue<int> teamQueue;
        queue<int> member[1005];

        cout << "Scenario #" << tc++ << '\n';

        string cmd;

        while (cin >> cmd) {

            if (cmd == "STOP")
                break;

            if (cmd == "ENQUEUE") {

                int x;
                cin >> x;

                int t = teamOf[x];

                if (member[t].empty())
                    teamQueue.push(t);

                member[t].push(x);
            }
            else { // DEQUEUE

                int t = teamQueue.front();

                cout << member[t].front() << '\n';

                member[t].pop();

                if (member[t].empty())
                    teamQueue.pop();
            }
        }

        cout << '\n';
    }

    return 0;
}*/