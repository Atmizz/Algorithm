#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
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
const int N = 5e5 + 20;
struct HeavyDecomp {
	// Don't forget to dfs1 and dfs2!
	struct Edge {
		int to, net;
	}e[N<<1];
	i64 p;
	int head[N], dep[N], sz[N], fa[N], son[N], top[N], cnt;
	void insert(int u, int v) {
		e[++cnt] = {v, head[u]};
		head[u] = cnt;
	}
	void dfs1(int u, int pa) {
		fa[u] = pa; sz[u] = 1; dep[u] = dep[pa] + 1;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
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
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
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
	int n, m, s;
	std :: cin >> n >> m >> s;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		HeavyLCA.insert(u, v);
		HeavyLCA.insert(v, u);
	}
	HeavyLCA.dfs1(s, s);
	HeavyLCA.dfs2(s, s);
	while(m --) {
		int x, y;
		std :: cin >> x >> y;
		std :: cout << HeavyLCA.LCA(x, y) << nl;
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