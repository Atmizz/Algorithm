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
const int N = 2e5 + 20;
std :: vector <int> adj[N];
int n, mk[N], dp[N];
void dfs1(int u, int fa) {
	dp[u] = mk[u] ? 1 : -1;
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		dfs1(v, u);
		dp[u] += std :: max(dp[v], 0);
	}
}
void dfs2(int u, int fa) {
	if(dp[u] >= 0) {
		if(dp[fa] - dp[u] > 0) {
			dp[u] += dp[fa] - dp[u];
		}
	} else {
		dp[u] = std :: max(dp[fa] + (mk[u] ? 1 : -1), dp[u]);
	}
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		dfs2(v, u);
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> mk[i];
	}
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 1);
	dfs2(1, 1);
	for(int i = 1; i <= n; ++ i) {
		std :: cout << dp[i] << ' ';
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