//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Alpha {
    char id;
    int count;
};
bool compare(Alpha a, Alpha b) {
    if (a.count != b.count)
        return a.count > b.count;
    return a.id < b.id;
}
int main() {
    int n;
    cin >> n;
    cin.ignore();
    string s;
    vector<Alpha> data(26);
    for (int i = 0; i < 26; i++) {
        data[i].id = 'A' + i;
        data[i].count = 0;
    }
    while (n--) {
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            char c{};
            c = s[j];
            if (isalpha(c)) {
                data[toupper(c) - 'A'].count++;
            }
        }

    }
    sort(data.begin(), data.end(), compare);
    for (int i = 0; i < 26; i++) {
        if (data[i].count > 0) {
            cout << data[i].id << " " << data[i].count << endl;
        }
    }


}
