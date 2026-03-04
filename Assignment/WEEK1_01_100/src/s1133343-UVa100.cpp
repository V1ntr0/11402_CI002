#include <iostream>
using namespace std;
int main() {
	int i, j;
	while (cin >> i >> j) {//块i,j
		int max_ =0;
		for (int n = min(i, j); n <= max(i, j); n++) {//眖程秨﹍衡程(ij or ji)
			int n1 = n, count = 1;
			while (n1 != 1) {//n=1铬
				if (n1 % 2 != 0)
					n1 = 3 * n1 + 1;
				else n1 /= 2;
				count++;
			}
			max_ =max (max_, count);//程癹伴计
		}
		cout << i << " " << j << " " << max_<<endl;
	}
	
}