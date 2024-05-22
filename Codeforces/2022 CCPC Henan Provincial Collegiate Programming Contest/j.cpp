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
const int N = 1e6 + 20;
int n, val[N], la[N], ans[N];
struct HeavyQueryLCA {
	// Don't forget to dfs1 and dfs2!
	std :: vector <int> adj[N];
	int dep[N], sz[N], fa[N], son[N], top[N], minn[N];
	void init() {
		for(int i = 1; i < N; ++ i) {
			adj[i].clear();
		}
	}
	void insert(int u, int v) {
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int dfs1(int u, int pa) {
		fa[u] = pa; sz[u] = 1; dep[u] = dep[pa] + 1;
		minn[u] = val[u];
		for(auto v : adj[u]) {
			if(v == pa) {
				continue ;
			}
			minn[u] = min(minn[u], dfs1(v, u));
			sz[u] += sz[v];
			if(sz[son[u]] < sz[v]) {
				son[u] = v;
			}
		}
		return minn[u];
	}
	void dfs2(int u, int topf) {
		top[u] = topf;
		if(son[u]) {
			dfs2(son[u], topf);
		}
		for(auto v : adj[u]) {
			if(v == fa[u] || v == son[u]) {
				continue ;
			}
			dfs2(v, v);
		}
	}
	int LCA(int x, int y) {
		while(top[x] != top[y]) {
			if(dep[top[x]] > dep[top[y]]) {
				x = fa[top[x]];
			} else {
				y = fa[top[y]];
			}
		}
		return dep[x] < dep[y] ? x : y;
	}
}HeavyLCA;
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> val[i];
		la[val[i]] = i;
	}
	for(int i = 2; i <= n; ++ i) {
		int v;
		std :: cin >> v;
		HeavyLCA.insert(i, v);
	}
	HeavyLCA.dfs1(1, 1);
	HeavyLCA.dfs2(1, 1);
	ans[0] = n - HeavyLCA.sz[la[0]];
	for(auto v : HeavyLCA.adj[la[0]]) {
		if(v == HeavyLCA.fa[la[0]]) {
			continue ;
		}
		ans[0] = max(ans[0], HeavyLCA.sz[v]);
	}
	ans[n] = n;
	int u = la[0];
	for(int i = 1; i <= n; ++ i) {
		std :: sort(HeavyLCA.adj[i].begin(), HeavyLCA.adj[i].end(), [&](int a, int b) {
			return HeavyLCA.minn[a] < HeavyLCA.minn[b];
		});
	}
	for(int i = 1; i < n; ++ i) {
		int lca = HeavyLCA.LCA(u, la[i-1]);
 		int lca2 = HeavyLCA.LCA(lca, la[i]);
 		if(lca2 != lca) {
 			if(lca2 == la[i]) {
	 			int SZ;
 				for(auto v : HeavyLCA.adj[lca2]) {
 					if(v == HeavyLCA.fa[lca2]) {
 						continue ;
 					}
 					if(HeavyLCA.minn[v] < i) {
 						SZ = HeavyLCA.sz[v];
 						break;
 					}
 				}
 				ans[i] = SZ;
 			} else {
 				ans[i] = n - HeavyLCA.sz[la[i]];
 			}
 		} else {
 			if(HeavyLCA.minn[la[i]] >= i) {
 				ans[i] = n - HeavyLCA.sz[la[i]];
 			} else {
 				if(lca == la[i]) {
	 				int cnt = 0, SZ;
	 				for(auto v : HeavyLCA.adj[lca]) {
	 					if(v == HeavyLCA.fa[lca]) {
	 						continue ;
	 					}
	 					if(HeavyLCA.minn[v] < i) {
	 						cnt ++;
	 						SZ = HeavyLCA.sz[v];
	 						if(cnt == 2) {
	 							break;
	 						}
	 					}
	 				}
	 				if(cnt == 1) {
	 					ans[i] = SZ;
	 				}
	 			}
 			}
 		}
		u = lca;
	}
	for(int i = 0; i <= n; ++ i) {
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