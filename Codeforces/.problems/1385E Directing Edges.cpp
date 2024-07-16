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
std :: vector <int> adj[N];
void solve() {
	int n, m, tot = 0;
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		adj[i].clear();
	}
	std :: vector <int> dep(n+1), deg(n+1);
	std :: vector <PII> ans;
	std :: vector <PII> e;
	for(int i = 0; i < m; ++ i) {
		int op, u, v;
		std :: cin >> op >> u >> v;
		if(op == 0) {
			e.pb({u, v});
		} else {
			adj[u].pb(v);
			deg[v] ++;
			ans.pb({u, v});
		}
	}
	std :: queue <int> q;
	for(int i = 1; i <= n; ++ i) {
		if(!deg[i]) {
			q.push(i);
		}
	}
	while(sz(q)) {
		int u = q.front(); q.pop();
		dep[u] = ++ tot;
		for(auto &v : adj[u]) {
			deg[v] --;
			if(!deg[v]) {
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(deg[i]) {
			std :: cout << "NO\n";
			return ;
		}
		if(!dep[i]) {
			dep[i] = ++ tot;
		}
	}
	for(auto &[u, v] : e) {
		if(dep[u] < dep[v]) {
			ans.pb({u, v});
		} else {
			ans.pb({v, u});
		}
	}
	std :: cout << "YES\n";
	for(auto &[u, v] : ans) {
		std :: cout << u << ' ' << v << nl;
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}