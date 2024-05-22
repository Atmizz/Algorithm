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
int dep[N], dp[N], n, k, vis[N];
std :: vector <int> adj[N];
bool flag;
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	dp[u] = INF;
	if(vis[u]) {
		dp[u] = 0;
		return ;
	}
	if(adj[u].size() == 1) {
		return ;
	}
	dp[u] = INF;
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		dfs(v, u);
		dp[u] = std :: min(dp[u], dp[v] + 1);
	}
}
void check(int u, int fa) {
	if(flag) {
		return ;
	}
	// deb(u);
	if(adj[u].size() == 1) {
		if(vis[u] == 0) {
			flag = 1;
			return ;
		}
	}
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		if(dep[v] < dp[v]) {
			check(v, u);
		}
	}
}
void solve() {
	dep[0] = -1;
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		vis[i] = 0;
		adj[i].clear();
	}
	for(int i = 1; i <= k; ++ i) {
		int x;
		std :: cin >> x;
		vis[x] = 1;
	}
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	adj[1].push_back(0);
	dfs(1, 0);
	flag = 0;
	check(1, 0);
	if(flag) {
		std :: cout << "YES\n";
	} else {
		std :: cout << "NO\n";
	}
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