#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n;
i64 c[N], sz[N], dep[N], sum, dp[N], szc[N], ans = LLINF;
std :: vector <int> adj[N];
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	sz[u] = 1;
	szc[u] = c[u];
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		dfs(v, u);
		szc[u] += szc[v];
		sz[u] += sz[v];
	}
}
void calc(int u, int fa) {
	if(u != 1) {
		// std :: cout << u << ' ' << dp[fa] << ' ' << sum << ' ' << szc[u] << '\n';
		dp[u] = dp[fa] + sum - szc[u] * 2;
	}
	for(auto v : adj[u]) {
		if(v == fa) {
			continue ;
		}
		calc(v, u);
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> c[i];
		sum += c[i];
	}
	dfs(1, 1);
	for(int i = 1; i <= n; ++ i) {
		dp[1] += (dep[i] - 1) * c[i];
	}
	calc(1, 1);
	for(int i = 1; i <= n; ++ i) {
		ans = std :: min(ans, dp[i]);
	}
	std :: cout << ans << '\n';
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