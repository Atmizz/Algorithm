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
std :: vector <int> adj[N];
int sz[N];
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	std :: vector <i64> dp1(n+1);
	std :: vector <int> fa(n+1);
	auto dfs1 = [&](auto dfs1, int u, int pa) -> void {
		fa[u] = pa; sz[u] = 1; dp1[u] = 1;
		for(auto v : adj[u]) {
			if(v == pa) {
				continue ;
			}
			dfs1(dfs1, v, u);
			sz[u] += sz[v];
			dp1[u] += sz[v] + dp1[v];
		}
	};
	dfs1(dfs1, 1, 1);
	i64 ans = 0;
	auto dfs2 = [&](auto dfs2, int u, i64 res) -> void {
		// std :: cout << u << ' ' << res << nl << nl;
		if(sz(adj[u]) == 1 && u != 1) {
			ans = max(ans, res);
			return ;
		}
		int SZ = 0;
		i64 DP = 0;
		for(auto v : adj[u]) {
			if(v == fa[u]) {
				continue ;
			}
			SZ += sz[v];
			DP += dp1[v];
		}
		for(auto v : adj[u]) {
			if(v == fa[u]) {
				continue ;
			}
			dfs2(dfs2, v, res + DP - dp1[v] + n - sz[v]);
		}
	};
	dfs2(dfs2, 1, n);
	std :: cout << ans;
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