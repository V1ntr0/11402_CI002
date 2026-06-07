#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    for (int i = 1; i <= T; i++) {
        int n;
        string field;
        cin >> n >> field;

        int scarecrows = 0;
        for (int i = 0; i < n; ) {
            if (field[i] == '.') {
                scarecrows++;
                i += 3;
            }
            else {
                i++;
            }
        }

        cout << "Case " << i << ": " << scarecrows << endl;
    }
    return 0;
}
