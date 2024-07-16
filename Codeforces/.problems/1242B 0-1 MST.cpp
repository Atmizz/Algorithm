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
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <int> pa(n+1), deg(n+1);
	for(int i = 1; i <= n; ++ i) {
		pa[i] = i;
	}
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		deg[u] ++; deg[v] ++;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int rt = 1;
	for(int i = 1; i <= n; ++ i) {
		if(deg[i] < deg[rt]) {
			rt = i;
		}
	}
	auto find = [&](auto find, int x) -> int {
		return x == pa[x] ? x : pa[x] = find(find, pa[x]);
	};
	std :: set <int> s;
	for(int i = 1; i <= n; ++ i) {
		if(i != rt) {
			s.insert(i);
		}
	}
	for(auto &v : adj[rt]) {
		s.erase(v);
	}
	for(auto &v : s) {
		pa[v] = rt;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++ i) {
		int j = find(find, i);
		if(j == rt) {
			continue ;
		}
		std :: vector <int> vis(n+1);
		for(int k = 1; k <= n; ++ k) {
			if(i != k) {
				vis[k] = 1;
			}
		}
		for(auto &v : adj[i]) {
			vis[v] = 0;
		}
		int uu = find(find, i);
		for(int k = 1; k <= n; ++ k) {
			if(vis[k] == 0) {
				continue ;
			}
			int vv = find(find, k);
			if(vv != uu) {
				pa[vv] = uu;
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		pa[i] = find(find, pa[i]);
	}
	std :: sort(pa.begin() + 1, pa.end());
	for(int i = 2; i <= n; ++ i) {
		if(pa[i] != pa[i-1]) {
			ans ++;
		}
	}
	std :: cout << ans << nl;
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