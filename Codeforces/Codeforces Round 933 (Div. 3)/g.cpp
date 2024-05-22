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
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <PII> g[n+m+1];
	std :: map <int, int> mp;
	for(int i = 1; i <= m; ++ i) {
		int u, v, w;
		std :: cin >> u >> v >> w;
		if(!mp[w]) {
			mp[w] = ++ n;
		}
		g[u].push_back({mp[w], 1});
		g[v].push_back({mp[w], 1});
		g[mp[w]].push_back({u, 0});
		g[mp[w]].push_back({v, 0});
	}
	int st, ed;
	std :: cin >> st >> ed;
	std :: vector <int> dis(n+m+1, INF), vis(n+m+1, 0);
	dis[st] = 0;
	std :: deque <int> q;
	q.push_back(st);
	while(q.size()) {
		int u = q.front(); q.pop_front();
		if(vis[u]) {
			continue;
		}
		vis[u] = 1;
		for(auto [v, w] : g[u]) {
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(w) q.push_back(v);
				else q.push_front(v);
			}
		}
	}
	std :: cout << dis[ed] << '\n';
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