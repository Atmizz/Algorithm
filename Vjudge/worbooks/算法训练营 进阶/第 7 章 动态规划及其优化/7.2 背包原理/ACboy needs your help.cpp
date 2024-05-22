#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
int n, m, a[N][N], f[N];
void solve() {
	while(1) {
		std :: cin >> n >> m;
		if(n == 0) return ;
		for(int i = 1; i <= m; ++ i) f[i] = 0;
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= m; ++ j)
				std :: cin >> a[i][j];
		for(int i = 1; i <= n; ++ i)
			for(int j = m; j >= 0; -- j)
				for(int k = 1; k <= j; ++ k)
					f[j] = std :: max(f[j], f[j-k] + a[i][k]);
		std :: cout << f[m] << endl;
	}
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