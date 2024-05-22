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
const int N = 1e5 + 20;
// 已经预设n, m，仅需要输入边即可。
struct TarjanAlgorithm {
	std :: vector <int> adj1[N], adj2[N];
	int n, m, dfn[N], low[N], bel[N], deg[N], tot, dnf;
	i64 val1[N], val2[N], f[N];
	std :: stack <int> s;
	void init() {
		std :: fill(val2 + 1, val2 + 1 + n, 0);
		std :: fill(dfn + 1, dfn + 1 + n, 0);
		std :: fill(low + 1, low + 1 + n, 0);
		std :: fill(bel + 1, bel + 1 + n, 0);
		for(int i = 1; i <= n; ++ i) {
			adj1[i].clear();
			adj2[i].clear();
		}
		tot = 0;
		dnf = 0;
	}
	void insert1(int u, int v) {
		adj1[u].push_back(v);
	}
	void insert2(int u, int v) {
		adj2[u].push_back(v);
	}
	void tarjan(int u) {
		dfn[u] = low[u] = ++ dnf;
		s.push(u);
		for(auto v : adj1[u]) {
			if(!dfn[v]) {
				tarjan(v);
				low[u] = min(low[u], low[v]);
			} else if(!bel[v]) {
				low[u] = min(low[u], dfn[v]);
			}
		}
		if(low[u] == dfn[u]) {
			tot ++;
			while((int) s.size()) {
				int v = s.top(); s.pop();
				bel[v] = tot;
				val2[tot] += val1[v];
				if(v == u) {
					break;
				}
			}
		}
	}
	void topo() {
		std :: fill(f + 1, f + 1 + tot, 0);
		std :: queue <int> q;
		for(int i = 1; i <= tot; ++ i) {
			if(!deg[i]) {
				q.push(i);
				f[i] = val2[i];
			}
		}
		while((int) q.size()) {
			int u = q.front(); q.pop();
			for(auto v : adj2[u]) {
				deg[v] --;
				f[v] = max(f[v], f[u] + val2[v]);
				if(deg[v] == 0) {
					q.push(v);
				}
			}
		}
	}
	void solve() {
		for(int i = 1; i <= n; ++ i) {
			if(!dfn[i]) {
				tarjan(i);
			}
		}
		for(int u = 1; u <= n; ++ u) {
			for(auto v : adj1[u]) {
				if(bel[u] != bel[v]) {
					insert2(bel[u], bel[v]);
					deg[bel[v]] ++;
				}
			}
		}
		topo();
		i64 ans = 0;
		for(int i = 1; i <= tot; ++ i) {
			ans = max(ans, f[i]);
		}
		std :: cout << ans << '\n';
	}
}Tarjan;
void solve() {
	std :: cin >> Tarjan.n >> Tarjan.m;
	for(int i = 1; i <= Tarjan.n; ++ i) {
		std :: cin >> Tarjan.val1[i];
	}
	for(int i = 1; i <= Tarjan.m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		Tarjan.insert1(u, v);
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
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}