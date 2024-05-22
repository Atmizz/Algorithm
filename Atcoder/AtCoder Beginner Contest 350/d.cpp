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
const int N = 2e5 + 20;
int deg[N], n, m, vis[N], cnt, num;
std :: vector <int> adj[N];
void dfs(int u, int fa) {
	cnt ++; num += deg[u]; vis[u] = 1;
	for(auto v : adj[u]) {
		if(v == fa) {
			continue ;
		}
		if(!vis[v]) {
			dfs(v, u);
		}
	}
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		int x, y;
		std :: cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
		deg[x] ++;
		deg[y] ++;
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		if(!vis[i]) {
			cnt = 0, num = 0;
			dfs(i, i);
			// deb(cnt); deb(num);
			ans += 1LL * cnt * (cnt - 1) / 2 - num / 2;
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