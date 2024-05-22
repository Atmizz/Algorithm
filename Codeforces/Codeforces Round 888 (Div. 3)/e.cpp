#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define int long long
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <int> ans(n+1, -1), deg(n+1);
	for(int i = 1; i <= n; ++ i) {
		int c; std :: cin >> c;
		if(ans[i] == -1) ans[i] = c;
	}
	for(int i = 1; i <= k; ++ i) {
		int x; std :: cin >> x;
		ans[x] = 0;
	}
	std :: vector < std :: vector <int> > adj(n+1), g(n+1);
	for(int i = 1; i <= n; ++ i) {
		int m; std :: cin >> m;
		for(int j = 1; j <= m; ++ j) {
			int u; std :: cin >> u;
			adj[u].push_back(i);
			g[i].push_back(u);
		}
		deg[i] = m;
	}
	std :: vector <int> q;
	for(int i = 1; i <= n; ++ i)
		if(deg[i] == 0) q.push_back(i);
	for(int i = 0; i < q.size(); ++ i) {
		int u = q[i];
		if(deg[u] == 0) {
			int sum = 0;
			for(auto v : g[u]) sum += ans[v];
			if(g[u].size() != 0) ans[u] = std :: min(ans[u], sum);
			for(auto v : adj[u]) {
				deg[v] --;
				if(deg[v] == 0) q.push_back(v);
			}
		}
	}
	for(int i = 1; i <= n; ++ i)
		std :: cout << ans[i] << " \n"[i == n];
}

signed main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}