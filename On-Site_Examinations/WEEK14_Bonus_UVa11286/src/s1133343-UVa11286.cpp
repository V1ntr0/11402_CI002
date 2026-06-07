#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        map<vector<int>, int> counts;
        int max_f = 0;

        for (int i = 0; i < n; i++) {
            vector<int> courses(5);
            for (int j = 0; j < 5; j++) cin >> courses[j];
            sort(courses.begin(), courses.end());
            
            counts[courses]++;
            max_f = max(max_f, counts[courses]);
        }

        int total_popular = 0;
       for (pair<vector<int>, int> p : counts) {
            if (p.second == max_f) {
                total_popular += p.second;
        }
}
        cout << total_popular << endl;
    }
    return 0;
}