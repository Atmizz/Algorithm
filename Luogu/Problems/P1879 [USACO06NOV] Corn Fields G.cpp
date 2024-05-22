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
const int Mod = 1e8;
const int N = 13;
const int M = 110;
int n, m, g[N];
i64 dp[M][1<<N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			int x;
			std :: cin >> x;
			if(x) {
				g[i] += (1 << (j - 1));
			}
		}
	}
	std :: vector <int> st[M];
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < 1 << m; ++ j) {
			if(((j << 1) & j) || (j & g[i]) != j) {
				continue;
			}
			st[i].push_back(j);
		}
	}
	st[0].push_back(0);
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++ i) {
		for(auto s : st[i]) {
			for(auto t : st[i-1]) {
				if(s & t) {
					continue;
				}
				dp[i][s] = (dp[i][s] + dp[i-1][t]) % Mod;
			}
		}
	}
	i64 ans = 0;
	for(auto s : st[n]) {
		ans = (ans + dp[n][s]) % Mod;
	}
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