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
int dep[N], n, k, st, ed, a[N], fa[N], res[N], ans;
std :: vector <int> adj[N];
void dfs1(int u, int pa) {
	fa[u] = pa;
	dep[u] = dep[pa] + 1;
	for(auto v : adj[u]) {
		if(pa == v) {
			continue;
		}
		dfs1(v, u);
	}
}
void dfs2(int u) {
	if(u == 0) {
		return ;
	}
	dep[u] = -dep[u];
	dfs2(fa[u]);
}
void dfs3(int u) {
	if(dep[u] < 0) {
		return ;
	}
	ans += 2;
	dep[u] = -dep[u];
	dfs3(fa[u]);
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		adj[i].clear();
	}
	std :: cin >> st >> ed;
	for(int i = 1; i <= k; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i < n; ++ i) {
		int x, y;
		std :: cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ans = 0;
	dfs1(st, 0);
	dfs2(ed);
	std :: sort(a + 1, a + 1 + k);
	for(int i = 1; i <= k; ++ i) {
		if(a[i] == a[i-1]) {
			continue;
		}
		dfs3(a[i]);
	}
	std :: cout << ans - dep[ed] - 1 << '\n';
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