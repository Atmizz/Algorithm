#include "testlib.h"
#include <bits/stdc++.h>
int main(int argc, char** argv) {
	freopen("5.in", "w", stdout);
	registerGen(argc, argv, 1);
	int n = rnd.next(1500, 2000), m = rnd.next(1500, 2000);
	std :: cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			int a = rnd.next(0, 1);
			std :: cout << a << ' ';
		}
		std :: cout << '\n';
	}
	return 0; 
}
