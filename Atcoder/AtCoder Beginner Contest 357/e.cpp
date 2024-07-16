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
int sz[N], a[N], n, cnt, dfn[N], low[N], dnf, deg[N], vis[N];
i64 ans;
int dfs(int u) {
	dfn[u] = low[u] = ++ dnf;
	if(dfn[a[u]]) {
		low[u] = min(low[u], dfn[a[u]]);
		if(!sz[a[u]]) {
			sz[u] = dfn[u] - low[u] + 1;
			int v = a[u];
			vis[u] = 1;
			while(v != u) {
				sz[v] = sz[u];
				vis[v] = 1;
				v = a[v];
			}
			ans += 1LL * sz[u] * sz[u];
		} else {
			sz[u] = sz[a[u]] + 1;
			ans += sz[u];
		}
	} else {
		int res = dfs(a[u]) + 1;
		low[u] = min(dfn[u], low[a[u]]);
		if(!vis[u]) {
			sz[u] = res;
			ans += res;
		}
	}
	return sz[u];
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		deg[a[i]] ++;
	}
	for(int i = 1; i <= n; ++ i) {
		if(!deg[i]) {
			dfs(i);
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(!sz[i]) {
			int u = a[i];
			int cnt = 1;
			sz[i] = 1;
			while(u != i) {
				sz[u] = ++ cnt;
				u = a[u];
			}
			ans += 1LL * cnt * cnt;
		}
		// std :: cout << i << ' ' << sz[i] << nl;
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