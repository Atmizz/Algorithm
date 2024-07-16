#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 29;
std :: vector <PII> adj[N];
int fa[N][21];
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> c(n+1), dep(n+1), ans(n+1);
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb({v, i});
		adj[v].pb({u, i});
	}
	int m;
	auto dfs = [&](auto dfs, int u, int pa) -> void {
		fa[u][0] = pa;
		dep[u] = dep[pa] + 1;
		for(int i = 1; dep[u] - (1 << i) > 0; ++ i) {
			fa[u][i] = fa[fa[u][i-1]][i-1];
		}
		for(auto &[v, id] : adj[u]) {
			if(v == pa) {
				continue ;
			}
			dfs(dfs, v, u);
		}
	};
	dfs(dfs, 1, 1);
	auto lca = [&](int x, int y) -> int {
		if(dep[x] < dep[y]) {
			std :: swap(x, y);
		}
		for(int i = 20; i >= 0; -- i) {
			if(dep[fa[x][i]] >= dep[y]) {
				x = fa[x][i];
			}
		}
		if(x == y) {
			return x;
		}
		for(int i = 20; i >= 0; -- i) {
			if(fa[x][i] != fa[y][i]) {
				x = fa[x][i];
				y = fa[y][i];
			}
		}
		return fa[x][0];
	};
	std :: cin >> m;
	while(m --) {
		int x, y;
		std :: cin >> x >> y;
		c[x] ++;
		c[y] ++;
		// std :: cout << x << ' ' << y << ' ' << lca(x, y) << nl;
		c[lca(x, y)] -= 2;
	}
	auto calc = [&](auto calc, int u, int pa) -> void {
		for(auto &[v, id] : adj[u]) {
			if(v == pa) {
				continue ;
			}
			calc(calc, v, u);
			c[u] += c[v];
			// std :: cout << v << ' ' << c[v] << nl;
			ans[id] = c[v];
		}
	};
	calc(calc, 1, 1);
	for(int i = 1; i < n; ++ i) {
		std :: cout << ans[i] << ' ';
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}