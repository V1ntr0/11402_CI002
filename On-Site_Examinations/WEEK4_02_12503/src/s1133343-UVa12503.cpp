#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	if (t <= 0) return 0;
	while ( t--) {
		//if (t <= 0) break;
			int a = 0;
			cin >> n;
			//cin.ignore();

			vector<int> history(n+1);
			
			for (int i = 0; i < n; i++){
				string s;
				//getline(cin, s);
				cin>>s;
				if (s == "RIGHT") {
					history[i] = 1;
				}
				else if (s == "LEFT") {
					history[i] = -1;
				}
				else {
					string junk; 
					int num=0;
					// for (int z = 8; z < s.length(); z++) {
					// 	if (s[z] >= '0' && s[z] <= '9')
					// 		num = num * 10 + s[z] - '0';
					// }
					cin >> junk >> num; 
					history[i] = history[num - 1];
				}
				a += history[i];
			}
			cout << a << endl;
			
	}
	return 0;
}
