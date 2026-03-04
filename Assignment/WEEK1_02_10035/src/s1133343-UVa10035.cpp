#include <iostream>
using namespace std;
int main() {
	int i, j;
	while (cin >> i >> j) {//块i,j块0 0挡
		if (i == 0 && j == 0)
			break;
		int carry = 0,temp=0;
		while (i > 0 || j > 0 ||temp > 0) {//计常=0挡
			int s = i % 10 + j % 10+temp;//s璸衡Τ⊿Τ秈(рㄢ计程计+秈计)
			if (s >= 10)//狦璶秈carry+1
				carry++;
			//ㄢ计埃10秈︽计秈temp琌秈计(s)埃10
			temp = s / 10;
			i /= 10;
			j /= 10;
		}
		//块秈Ω计
		if (carry == 0)
			cout << "No carry operation."<<endl;
		else if(carry == 1)
			cout << carry << " carry operation." << endl;
		else
			cout << carry << " carry operations."<<endl;
	}
	return 0;
}