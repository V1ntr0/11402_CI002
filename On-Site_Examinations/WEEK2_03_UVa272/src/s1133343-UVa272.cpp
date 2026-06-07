#include <iostream>
using namespace std;

int main() {
	int check = 1;
	char text;
	while (cin.get(text)) {
		//遇到第一個引號時，輸出``，遇到第二個引號輸出''。check記錄第一個還是第二個引號
		if (text == '"') {
			if (check == 1)
				cout << "``";
			else
				cout << "''";
			check = (check + 1) % 2;
		}
		else
			cout << text;
	}
}