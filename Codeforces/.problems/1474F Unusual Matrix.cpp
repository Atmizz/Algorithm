#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n;
	std :: cin >> n;
	std :: vector a(n, std :: vector <int> (n)), b(n, std :: vector <int> (n));
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++ j) {
			char ch; std :: cin >> ch;
			a[i][j] = ch - 48;
		}
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++ j) {
			char ch; std :: cin >> ch;
			b[i][j] = ch - 48;
		}
	for(int i = 0; i < n; ++ i)
		if(a[0][i] != b[0][i])
			for(int j = 0; j < n; ++ j)
				a[j][i] ^= 1;
	for(int i = 1; i < n; ++ i)
		if(a[i][0] != b[i][0])
			for(int j = 0; j < n; ++ j)
				a[i][j] ^= 1;
	for(int i = 1; i < n; ++ i)
		for(int j = 0; j < n; ++ j)
			if(a[i][j] != b[i][j]) {
				std :: cout << "NO\n";
				return ;
			}
	std :: cout << "YES\n";
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}