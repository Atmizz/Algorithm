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
const int N = 1e5 + 20;
std :: vector <i64> l(N), r(N), adj[N];
std :: vector dp(N, std :: vector <i64> (2));
void dfs(int u, int fa) {
	for(auto v : adj[u]) {
		if(v == fa) continue;
		dfs(v, u);
		dp[u][0] += std :: max(dp[v][0] + std :: abs(l[u] - l[v]), dp[v][1] + std :: abs(l[u] - r[v]));
		dp[u][1] += std :: max(dp[v][0] + std :: abs(r[u] - l[v]), dp[v][1] + std :: abs(r[u] - r[v]));
	}
}
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		adj[i].clear(), dp[i][0] = dp[i][1] = 0;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> l[i] >> r[i];
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 1);
	std :: cout << std :: max(dp[1][0], dp[1][1]) << endl;
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