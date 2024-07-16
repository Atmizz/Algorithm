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
const int N = 2e5 + 20;
struct Node {
	int u, v, w, id;
	friend bool operator < (Node a, Node b) {
		return a.w < b.w;
	}
};
std :: vector <PII> adj[N];
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <Node> a(m);
	int tot = 0;
	for(auto &[u, v, w, id] : a) {
		std :: cin >> u >> v >> w;
		id = ++ tot;
	}
	std :: sort(a.begin(), a.end());
	std :: vector <int> pa(n+1), dep(n+1);
	for(int i = 1; i <= n; ++ i) {
		pa[i] = i;
	}
	auto find = [&](auto find, int x) -> int {
		return x == pa[x] ? x : pa[x] = find(find, pa[x]);
	};
	i64 res = 0;
	for(auto &[u, v, w, id] : a) {
		int uu = find(find, u);
		int vv = find(find, v);
		if(uu != vv) {
			pa[uu] = vv;
			adj[u].pb({v, w});
			adj[v].pb({u, w});
			res += w;
		}
	}
	std :: vector <i64> ans(m+1);
	std :: vector fa(n+1, std :: vector <int> (21));
	std :: vector dis(n+1, std :: vector <int> (21));
	auto dfs = [&](auto dfs, int u, int FA) -> void {
		fa[u][0] = FA; dep[u] = dep[FA] + 1;
		for(int i = 1; dep[u] - (1 << i) >= 0; ++ i) {
			fa[u][i] = fa[fa[u][i-1]][i-1];
			dis[u][i] = max(dis[u][i-1], dis[fa[u][i-1]][i-1]);
		}
		for(auto [v, w] : adj[u]) {
			if(v == FA) {
				continue ;
			}
			dis[v][0] = w;
			dfs(dfs, v, u);
		}
	};
	auto findMax = [&](int x, int y) -> int {
		if(dep[x] < dep[y]) {
			std :: swap(x, y);
		}
		int d = 0;
		for(int i = 20; i >= 0; -- i) {
			if(dep[fa[x][i]] >= dep[y]) {
				d = max(d, dis[x][i]);
				x = fa[x][i];
			}
		}
		if(x == y) {
			return d;
		}
		for(int i = 20; i >= 0; -- i) {
			if(fa[x][i] != fa[y][i]) {
				d = max(d, max(dis[x][i], dis[y][i]));
				x = fa[x][i];
				y = fa[y][i];
			}
		}
		return max(d, max(dis[x][0], dis[y][0]));
	};
	dfs(dfs, 1, 1);
	for(auto &[u, v, w, id] : a) {
		ans[id] = res + w - findMax(u, v);
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cout << ans[i] << nl;
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