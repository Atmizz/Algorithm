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
const int N = 3e4 + 20;
struct CutEdgeAlgorithm {
	int n, m, dfn[N], low[N], tot, ans;
	std :: vector <int> adj[N];
	void init() {
		tot = 0; ans = 0;
		std :: fill(dfn + 1, dfn + 1 + n, 0);
		for(int i = 1; i <= n; ++ i) {
			adj[i].clear();
		}
	}
	inline void insert(int u, int v) {
		adj[u].push_back(v);
	}
	void tarjan(int u, int fa) {
		dfn[u] = low[u] = ++ tot;
		for(auto v : adj[u]) {
			if(v == fa) {
				continue ;
			}
			if(!dfn[v]) {
				tarjan(v, u);
				low[u] = min(low[u], low[v]);
				if(low[v] > low[u]) {
					ans ++;
				}
			} else {
				low[u] = min(low[u], dfn[v]);
			}
		}
	}
	void solve() {
		for(int i = 1; i <= n; ++ i) {
			if(!dfn[i]) {
				tarjan(i, i);
			}
		}
		std :: cout << ans;
	}
}CutEdge;
void solve() {
		
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