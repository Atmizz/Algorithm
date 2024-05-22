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
const int N = 1e6 + 20;
const int M = 1e3 + 20;
int a[N], f[M][M], n, m;
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i], a[i] %= m;
	if(n > m) {
		std :: cout << "YES";
		return ;
	}
	for(int i = 1; i <= n; ++ i) {
		f[i][a[i]] = 1;
		for(int j = 1; j <= m; ++ j) {
			f[i][j] |= f[i-1][j];
			f[i][(j+a[i])%m] |= f[i-1][j];
		}
		if(f[i][0] == 1) {
			std :: cout << "YES";
			return ;
		}
	}
	std :: cout << "NO";
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