#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int n;
	std :: cin >> n;
	std :: vector a(n + 1, std :: vector <int> (n + 1));
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j) {
			char ch;
			std :: cin >> ch;
			a[i][j] = ch - 48;
		}
	int x = 0, y = 0;
	for(int i = 1; i <= n; ++ i) 
		if(a[1][i]) {
			x ++;
			for(int j = 1; j <= n; ++ j)
				a[j][i] ^= 1;
		}
	for(int i = 1; i <= n; ++ i)
		if(a[i][1]) {
			y ++;
			for(int j = 1; j <= n; ++ j)
				a[i][j] ^= 1;
		}
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			if(a[i][j]) {
				std :: cout << "-1";
				return ;
			}
	// deb(x); deb(y);
	std :: cout << std :: min(x, n - x) + std :: min(y, n - y);
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}