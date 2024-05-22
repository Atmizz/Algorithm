#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, m, T;
i64 sz[N], p[N];
std :: vector <int> adj[N];
// calculate the size of the tree
void dfs(int u, int fa) {
	sz[u] = 1;
	for(auto v : adj[u]) {
		if(v == fa) {
			continue;
		}
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		adj[i].clear();
	}
	// build the edge
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// input the p[]
	std :: cin >> m;
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> p[i];
	}
	// if m < n
	for(int i = m + 1; i < n; ++ i) {
		p[i] = 1;
	}
	// sort p 
	std :: sort(p + 1, p + 1 + m, [&](i64 x, i64 y) {
		return x > y;
	});
	if(m >= n) {
		int cnt = 0;
		for(int i = 2; i <= m; ++ i) {
			p[1] = p[1] * p[i] % Mod;
			cnt ++;
			if(cnt == m - n + 1) {
				break;
			}
		}
		for(int i = 2 + cnt; i <= m; ++ i) {
			p[i-cnt] = p[i];
		}
	}
	i64 ans = 0;
	dfs(1, 1);
	std :: sort(sz + 1, sz + 1 + n, [&](i64 x, i64 y) {
		return 1LL * (n - x) * x > 1LL * (n - y) * y;
	});
	for(int i = 1; i < n; ++ i) {
		// deb(sz[i] * (n - sz[i]))
		// deb(p[i])
		ans = (ans + (1LL * (n - sz[i]) * sz[i] * p[i]) % Mod) % Mod;
		// deb(ans);
	}
	std :: cout << ans << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}