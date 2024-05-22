#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(b > d) c -= 1, d += 60;
	printf("%d %d", c - a, d - b);
	return 0;
}