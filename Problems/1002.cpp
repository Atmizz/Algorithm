#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
int main() {
	int T, V0, t;
	std :: cin >> T;
	for(int i = 1; i <= T; ++ i) {
		std :: cin >> V0 >> t;
		std :: cout << 3 * t * t + 2 * t + 1 << " " << V0 + t * t * t + t * t + t << '\n';
	}
	return 0;
}