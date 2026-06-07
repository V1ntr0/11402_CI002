#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(){
    char s1,s2;
    while(cin.get(s1)) {

        int count1[128] = {}, count2[128] = {};
        int i, j;

        for(i = 0; i<s1.len(); i++)
            count1[s1[i]]++;
        cin.get(s2);
        for(i = 0; s2[i]; i++)
            count2[s2[i]]++;

        for(i = 0; i < 128; i++) {
            for(j = 0; j < count1[i] && j < count2[i]; j++)
                cout<<' '+i;
        }
        cout<<endl;
    }
    return 0;

}
