#include <iostream>
using namespace std;
int main() {
	long long s, d,sum;
	while (cin >> s >> d) {
		while (d > 0) {
			d -= s;
			if (d <= 0) break;
			s++;
		}
		cout << s<<endl;
	}

}