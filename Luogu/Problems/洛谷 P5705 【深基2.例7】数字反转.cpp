#include <iostream>
#include <cstring>
using namespace std;
string str;
int len;
int main() {
	cin >> str;
	len = str.length();
	for(int i = len - 1; i >= 0; i --)
		cout << str[i];
	return 0;
}