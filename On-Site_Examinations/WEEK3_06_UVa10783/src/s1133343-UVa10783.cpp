#include <iostream>
using namespace std;
int main() {
	int T, a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int sum = 0;
		cin >> a >> b;
		while (a <= b) {
			if (a % 2 == 0) {
				a += 1;
				continue;
			}
			sum += a;
			a += 2;
		}
		cout << "Case " << i + 1 <<": " << sum<<endl;

	}


}