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
int sz[N], dep[N], top[N], fa[N], son[N], n, k, a[N];
i64 dis[N];
std :: vector <PII> adj[N];
void dfs1(int u, int pa) {
	fa[u] = pa; dep[u] = dep[pa] + 1; sz[u] = 1;
	for(auto [v, t] : adj[u]) {
		if(v == pa) {
			continue ;
		}
		dis[v] = dis[u] + t;
		dfs1(v, u);
		sz[u] += sz[v];
		if(sz[son[u]] < sz[v]) {
			son[u] = v;
		}
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	if(son[u]) {
		dfs2(son[u], topf);
	}
	for(auto [v, t] : adj[u]) {
		if(v == fa[u] || v == son[u]) {
			continue ;
		}
		dfs2(v, v);
	}
}
int query(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] > dep[top[y]]) {
			x = fa[top[x]];
		} else {
			y = fa[top[y]];
		}
	}
	return dep[x] < dep[y] ? x : y;
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i < n; ++ i) {
		int u, v, t;
		std :: cin >> u >> v >> t;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
	}
	for(int i = 1; i <= k; ++ i) {
		std :: cin >> a[i];
	}
	dfs1(1, 1);
	dfs2(1, 1);
	i64 res = 0;
	for(int i = 1; i < k; ++ i) {
		int LCA = query(a[i], a[i+1]);
		res += dis[a[i]] + dis[a[i+1]] - 2 * dis[LCA];
	}
	for(int i = 1; i <= k; ++ i) {
		i64 ans = res;
		if(i != k) {
			int LCA = query(a[i], a[i+1]);
			ans -= dis[a[i]] + dis[a[i+1]] - 2 * dis[LCA];
		}
		if(i != 1) {
			int LCA = query(a[i], a[i-1]);
			ans -= dis[a[i]] + dis[a[i-1]] - 2 * dis[LCA];
		}
		if(i != 1 && i != k) {
			int LCA = query(a[i-1], a[i+1]);
			ans += dis[a[i-1]] + dis[a[i+1]] - 2 * dis[LCA];
		}
		std :: cout << ans << ' ';
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