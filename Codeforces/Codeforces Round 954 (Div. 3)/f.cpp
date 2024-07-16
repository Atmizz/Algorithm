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
const int N = 1e5 + 20;
// 已经预设n, m，仅需要输入边即可。
struct TarjanAlgorithm {
	std :: vector <int> adj[N];
	int n, m, dfn[N], low[N], deg[N], tot, dnf, sz[N];
	i64 ans;
	void init() {
		std :: fill(dfn + 1, dfn + 1 + n, 0);
		std :: fill(low + 1, low + 1 + n, 0);
		for(int i = 1; i <= n; ++ i) {
			adj[i].clear();
		}
		tot = 0;
		dnf = 0;
	}
	void insert(int u, int v) {
		adj[u].push_back(v);
	}
	void tarjan(int u, int fa) {
		dfn[u] = low[u] = ++ dnf; sz[u] = 1;
		for(auto v : adj[u]) {
			if(v == fa) {
				continue ;
			}
			if(!dfn[v]) {
				tarjan(v, u);
				sz[u] += sz[v];
				low[u] = min(low[u], low[v]);
				if(low[v] > dfn[u]) {
					int x = sz[v];
					// deb(x);
					// deb(n);
					ans = min(ans, 1LL * x * (x - 1) / 2 + 1LL * (n - x) * (n - x - 1) / 2);
				} 
			} else {
				low[u] = min(low[u], dfn[v]);
			}
		}
	}
	void solve() {
		ans = 1LL * n * (n - 1) / 2;
		for(int i = 1; i <= n; ++ i) {
			if(!dfn[i]) {
				tarjan(i, i);
			}
		}
		std :: cout << ans << '\n';
	}
}Tarjan;
void solve() {
	std :: cin >> Tarjan.n >> Tarjan.m;
	Tarjan.init();
	for(int i = 1; i <= Tarjan.m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		Tarjan.insert(u, v);
		Tarjan.insert(v, u);
	}
	Tarjan.solve();
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}