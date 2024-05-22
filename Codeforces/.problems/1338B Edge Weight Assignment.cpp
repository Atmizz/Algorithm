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
std :: vector <int> adj[N];
int leaf = -1;
void dfs1(int u, int fa) {
	if(leaf != -1) {
		return ;
	}
	if(sz(adj[u]) == 1) {
		leaf = u;
		return ;
	}
	for(auto v : adj[u]) {
		if(v == fa) {
			continue ;
		}
		dfs1(v, u);
	}
}
bool ok_AllEven = true;
void dfs2(int u, int fa, int dis) {
	if(sz(adj[u]) == 1) {
		// deb(u);
		// deb(dis);
		if(dis & 1) {
			ok_AllEven = false;
		}
	}
	for(auto v : adj[u]) {
		if(v == fa) {
			continue ;
		}
		dfs2(v, u, dis + 1);
	}
}
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1, 1);
	dfs2(leaf, leaf, 0);
	if(ok_AllEven) {
		std :: cout << 1 << ' ';
	} else {
		std :: cout << 3 << ' ';
	}
	int ans = n - 1;
	std :: vector <int> son(n+1);
	for(int i = 1; i <= n; ++ i) {
		if(sz(adj[i]) == 1) {
			son[adj[i][0]] ++;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(son[i] > 1) {
			// deb(i); deb(son[i]);
			ans -= son[i] - 1;
		}
	}
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