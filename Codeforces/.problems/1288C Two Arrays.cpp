#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
int n, m;
i64 f[2][15][N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		f[0][1][i] = f[1][1][i] = 1;
	for(int i = 2; i <= m; ++ i) {
		i64 res = 0;
		for(int j = 1; j <= n; ++ j) {
			res = (res + f[0][i-1][j]) % Mod;
			f[0][i][j] = res;
		}
	}
	for(int i = 2; i <= m; ++ i) {
		i64 res = 0;
		for(int j = n; j >= 1; -- j) {
			res = (res + f[1][i-1][j]) % Mod;
			f[1][i][j] = res;
		}
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i)
		for(int j = i; j <= n; ++ j)
			ans = (ans + f[0][m][i] * f[1][m][j] % Mod) % Mod;
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}