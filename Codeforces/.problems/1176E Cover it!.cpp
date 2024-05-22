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
const int N = 2e5 + 20;
int n, m, col[N], vis[N];
std :: vector <int> adj[N];
void dfs(int u, int mk) {
	col[u] = mk;
	for(auto v : adj[u]) {
		if(vis[v]) {
			continue;
		}
		vis[v] = 1;
		dfs(v, mk^1);
	}
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		adj[i].clear();
		vis[i] = 0;
	}
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vis[1] = 1;
	dfs(1, 0);
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		cnt += col[i];
	}
	int flag = 1;
	if(cnt <= n / 2) {
		std :: cout << cnt << '\n';
		
	} else {
		std :: cout << n - cnt << '\n';
		flag = 0;
	}
	for(int i = 1; i <= n; ++ i) {
		if(col[i] == flag) {
			std :: cout << i << ' ';
		}
	}
	std :: cout << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}