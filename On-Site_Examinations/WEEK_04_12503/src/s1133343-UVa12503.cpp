#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	if (t <= 0) return 0;
	while (t--) {
		if (t <= 0) break;
			int a = 0;
			cin >> n;
			cin.ignore();

			string s;
			vector<int> history(n+1);
			
			for (int i = 0; i < n; i++){
				getline(cin, s);
				if (s == "RIGHT") {
					history[i] = 1;
				}
				else if (s == "LEFT") {
					history[i] = -1;
				}
				else {
					int num=0;
					for (int z = 8; z < s.length(); z++) {
						if (s[z] >= '0' && s[z] <= '9')
							num = num * 10 + s[z] - '0';
					}
					history[i] = history[num-1];
				}
				a += history[i];
			}
			cout << a << endl;
			
	}
	return 0;
}
