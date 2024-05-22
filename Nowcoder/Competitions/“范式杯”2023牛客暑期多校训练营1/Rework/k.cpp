#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
using i64 = long long;

const int N = 1e5 + 200;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

int n, m, k;
ll ans;
void solve() {
	std :: cin >> n >> m >> k;
	std :: vector < std :: vector <int> > adj(n+1);
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std :: vector <int> dis(n+1, -1);
	std :: queue <int> q;
	std :: vector <int> deg(n+1);
	dis[1] = 0; q.push(1);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(auto v : adj[u])
			if(dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
	// for(int i = 1; i <= n; ++ i)
	// 	std :: cout << i << ' ' << dis[i] << '\n';
	for(int i = 1; i <= n; ++ i)
		if(dis[i] != -1 && dis[i] <= k) {
			ans ++;
			if(i != 1) ans -= (k - dis[i]) * 2 + 1;
			for(auto j : adj[i]) {
				if(dis[j] <= k && j > i) {
					deg[i] ++; deg[j] ++;
					ans += k * 2 - dis[j] - dis[i];
				}
			}
		}
	for(int i = 2; i <= n; ++ i)
		if(dis[i] != -1 && dis[i] <= k && deg[i] == 1)
			ans += k - dis[i];
	std :: cout << ans;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T;
	while(T --) solve();
	return 0;
}