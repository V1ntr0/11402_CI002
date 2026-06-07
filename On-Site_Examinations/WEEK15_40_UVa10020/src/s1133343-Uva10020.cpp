#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct seg{
    int l,r;
};
bool compare(seg a, seg b) {
    return a.l < b.l;
}
int main(){
    int casenum;
    cin>>casenum;
    while(casenum--){
        int m;
        cin>>m;
        int l,r;
        vector<seg> segment;
        while(cin>>l>>r&&(l!=0||r!=0))
            segment.push_back({l,r});
        sort(segment.begin(),segment.end(),compare);

        vector<seg>ans;

        int current_r=0;
        int i=0;
        bool possible=false;
        while(current_r<m){
            int best_i=-1;
            int best_r=current_r;

            while(i<segment.size()&& segment[i].l <= current_r){
                if (segment[i].r > best_r) {
                    best_r = segment[i].r;
                    best_i = i;
                }
                i++;
            }

            if (best_i == -1) break;

            ans.push_back(segment[best_i]);
            current_r = best_r;

            if (current_r >= m) {
                possible = true;
                break;
            }
        }
        if (possible) {
            cout << ans.size() <<endl;
            for (int k = 0; k < ans.size(); k++) {
                cout << ans[k].l << " " << ans[k].r << endl;
            }
        } else {
            cout << 0<<endl;
        }

        if (casenum > 0)
            cout << endl;

    }
    return 0;
}
