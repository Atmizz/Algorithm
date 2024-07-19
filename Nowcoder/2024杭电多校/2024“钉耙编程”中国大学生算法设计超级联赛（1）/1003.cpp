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
const int N = 5e5 + 20;
int n;
ull a[N], ans[N];
std :: vector <int> adj[N], vec[N];
void dfs(int u, int fa) {
	int rt = u;
	for(int &v : adj[u]) {
		if(v == fa) {
			continue ;
		}
		dfs(v, u);
		if(sz(vec[v]) > sz(vec[u])) {
			rt = v;
			vec[u] = vec[v];
		}
	}
	for(auto &v : adj[u]) {
		if(v == fa) {
			continue ;
		}
		if(v != rt) {
			for(auto &x : vec[v]) {
				vec[u].pb(x);
			}
		}
	}
	for(auto &v : adj[u]) {}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	dfs(1, 1);
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