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
const int N = 1e5 + 20;
int n, m, t[N], dp[N], ans = INF;
std :: vector <int> adj[N];
void dfs(int u, int fa) {
	if(t[u] != -1) {
		dp[u] = t[u];
	}
	std :: vector <int> res;
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		dfs(v, u);
		res.push_back(dp[v]);
	}
	std :: sort(res.begin(), res.end());
	if(res.size() > 1) {
		int tmp = 2;
		if(res[0] + 1 == res[1]) {
			tmp = 1;
		} else if(res[0] + 1 < res[1]) {
			tmp = 0;
		}
		ans = std :: min(ans, std :: max(res[0], res[1]) * 2 + tmp);
	}
	if(res.size()) {
		int tmp = 0;
		if(dp[u] == res[0]) {
			tmp = 1;
		}
		ans = std :: min(ans, std :: max(res[0], dp[u]) * 2 + tmp);
	}
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		dp[u] = std :: min(dp[u], dp[v] + 1);
	}
	// deb(dp[u]);
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; ++ i) {
		dp[i] = N;
		t[i] = -1;
	}
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		if(t[u] == -1) {
			t[u] = v;
		} else {
			ans = std :: min(ans, std :: max(t[u], v));
			t[u] = std :: min(t[u], v);
		}
	}
	dfs(1, 1);
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