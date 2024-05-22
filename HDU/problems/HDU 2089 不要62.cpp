#include <bits/stdc++.h>
#define ll long long
const int N = 12;

int len, f[N][11], a[N];

int calc(int x) {
	memset(f, 0, sizeof f);
	len = 0;
	while(x) a[++len] = x % 10, x /= 10;
	return dfs(1, 
}

int main() {
	int l, r;
	while(1) {
		std :: cin >> l >> r;
		if(l == 0 && r == 0) break;
		std :: cout << calc(r) - calc(l-1);
	}
	return 0;
}
