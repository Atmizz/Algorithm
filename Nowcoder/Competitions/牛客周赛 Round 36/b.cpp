#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
int n, m, x, g[N][N];
void solve() {
	std :: cin >> n >> m >> x;
	int sum = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
			sum += g[i][j];
		}
	}
	if(sum != x) {
		std :: cout << "wrong answer";
		return ;
	}
	int ans = 0;
	for(int i = 1; i <= m; ++ i)
		ans ^= g[1][i];
	for(int i = 2; i <= n; ++ i) {
		int res = 0;
		for(int j = 1; j <= m; ++ j) {
			res ^= g[i][j];
		}
		if(res != ans) {
			std :: cout << "wrong answer";
			return ;
		}
	}
	for(int i = 2; i <= m; ++ i) {
		int res = 0;
		for(int j = 1; j <= n; ++ j) {
			res ^= g[j][i];
		}
		if(res != ans) {
			std :: cout << "wrong answer";
			return ;
		}
	}
	std :: cout << "accepted";
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