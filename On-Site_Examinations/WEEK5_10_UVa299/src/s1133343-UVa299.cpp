#include <iostream>
using namespace std;
int main() {
	int n, l=0;
	cin >> n;
	int i, j;
	while (n > 0) {
		cin >> l;
		int train[l]{},count = 0;
		for (i = 0; i < l; i++) {
			cin>>train[i];
		}
		for (int a = 0; a < l; a++) {
			for (int b = 0; b < l-a-1;b++) {
				if (train[b] > train[b + 1]){
					swap(train[b], train[b + 1]);
					count++;
				}
			}
		}
		cout << "Optimal train swapping takes " << count << " swaps." << endl;
		n--;
	}


}
