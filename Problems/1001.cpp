#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
int main() {
	int n, a, b;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a >> b;
		std :: cout << a + b << '\n';
	}
	return 0;
}