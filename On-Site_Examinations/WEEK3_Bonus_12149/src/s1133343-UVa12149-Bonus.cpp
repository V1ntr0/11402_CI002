#include <iostream>
using namespace std;
//1*1所有的格子數會在n*n算出來
int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i * i;
		}
		cout << sum <<endl;
	}
	//8: 1:64 2:

}