#include<iostream>
#include<string>
using namespace std;
int main() {
	string text[101];
	int length=0;
	int index = 0;
	/*魁程计璸衡羆︽计*/
	while (getline(cin, text[index])) {
		if (length < text[index].length())
			length = text[index].length();
		index++;
	}
	/*パ程┕材块パ材┕程块ê︽狦⊿Τ干*/
	for (int i = 0; i < length; i++) {
		for (int j = index - 1; j >= 0; j--) {
			if (text[j].length() > i)
				cout << text[j][i];
			else
				cout << " ";
		}
		cout << endl;
	}
}