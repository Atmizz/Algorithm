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
std :: vector <int> adj[N+1];
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: vector <i64> b(n+1);
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	auto dfs1 = [&](auto dfs1, int u, int fa, int dep) -> i64 {
		b[u] = a[u];
		i64 res = 1LL * a[u] * dep;
		for(auto &v : adj[u]) {
			if(v == fa) {
				continue ;
			}
			res += dfs1(dfs1, v, u, dep + 1);
			b[u] += b[v];
		}
		return res;
	};
	i64 ans;
	auto dfs2 = [&](auto dfs2, int u, int fa, i64 res) -> void {
		ans = max(ans, res);
		for(auto &v : adj[u]) {
			if(v == fa) {
				continue ;
			}
			dfs2(dfs2, v, u, res + b[1] - b[v] * 2);
		}
	};
	ans = dfs1(dfs1, 1, 1, 0);
	dfs2(dfs2, 1, 1, ans);
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