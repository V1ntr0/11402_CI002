#include <iostream>
using namespace std;
int main() {
	int i, j;
	while (cin >> i >> j) {//��Ji,j
		int max_ =0;
		for (int n = min(i, j); n <= max(i, j); n++) {//�q�̤p�}�l���̤j(i��j or j��i)
			int n1 = n, count = 1;
			while (n1 != 1) {//n=1���X
				if (n1 % 2 != 0)
					n1 = 3 * n1 + 1;
				else n1 /= 2;
				count++;
			}
			max_ =max (max_, count);//���̤j���j���
		}
		cout << i << " " << j << " " << max_<<endl;
	}
	
}