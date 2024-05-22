#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int N = 5e5 + 200;

void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <int> dep(n+1, -1);
	std :: vector < std :: vector <int> > adj(n+1);
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		if(u == v) continue;
		adj[u].push_back(v);
	}
	std :: vector <int> vis(n+1), dis(n+1, -1);
	bool flag = 1;
	auto dfs = [&](auto self, int u) -> void {
		for(auto v : adj[u]) {
			if(vis[v] == 1) continue;
			if(vis[v] == 2 && dis[v] != dis[u] + 1) {
				flag = 0;
				return ;
			}
			if(!flag) return ;
			vis[v] = 1; dis[v] = dis[u] + 1;
			self(self, v);
			vis[v] ++;
		}
	};
	vis[1] = 1; dfs(dfs, 1);
	std :: cout << (flag ? "Yes\n" : "No\n");
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}