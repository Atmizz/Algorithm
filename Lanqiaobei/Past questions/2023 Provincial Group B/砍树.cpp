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
int sz[N], dep[N], son[N], fa[N], top[N], n, m, c[N], ans = -1;
std :: vector <PII> adj[N];
void dfs1(int u, int pa) {
	fa[u] = pa; dep[u] = dep[pa] + 1; sz[u] = 1;
	for(auto [v, id] : adj[u]) {
		if(v == pa) {
			continue ;
		}
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
	for(auto [v, id] : adj[u]) {
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
void dfs(int u) {
	int ID = 0;
	for(auto [v, id] : adj[u]) {
		if(v == fa[u]) {
			ID = id;
			continue ;
		}
		dfs(v);
		c[u] += c[v];
	}
	// std :: cout << u << ' ' << c[u] << '\n';
	if(c[u] == m) {
		ans = std :: max(ans, ID);
	}
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	dfs1(1, 1);
	dfs2(1, 1);
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		int lca = query(u, v);
		if(lca == u) {
			c[u] --;
			c[v] ++;
		} else if(lca == v) {
			c[v] --;
			c[u] ++;
		} else {
			c[u] ++;
			c[v] ++;
			c[lca] --;
		}
	}
	dfs(1);
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